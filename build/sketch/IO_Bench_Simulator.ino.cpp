#include <Arduino.h>
#line 1 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
//  Name:    GPIO_REV_2.ino
//  Created: 7/7/2021 11:54:20 AM
//  Author:  Ryan Corkery

// #include <avr/iom2560.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include <Ethernet.h>
// #include <MemoryFree.h>

// Debug
#define DEBUG 0                                               // debug true = 1, false = 0

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#elif DEBUG == 0
#define debug(x)
#define debugln(x)
#endif

// Arduino pinout
const int s1_out PROGMEM = 2;                                         // Speed signal 1 out of Arduino
const int s2_out PROGMEM = 3;
// ethernet pin 4
const int s3_out PROGMEM = 5;
const int s4_out PROGMEM = 6;
const int s5_out PROGMEM = 7;
const int s6_out PROGMEM = 8;
const int s7_out PROGMEM = 9;
// ethernet pin 10
const int s8_out PROGMEM = 11;
const int a1_out PROGMEM = 12;                                        // Analog signal 1 out of Arduino
const int a2_out PROGMEM = 13;
const int menu_interrupt PROGMEM = 18;                                // Interrupt is triggered when any menu button is pressed
// pin 20 - LCD SDA
// pin 21 - LCD SCL
const int menu_down PROGMEM = 22;
const int b1 PROGMEM = 23;                                            // Brake signal 1 out of Arduino
const int menu_up PROGMEM = 24;
const int b2 PROGMEM = 25;
const int menu_left PROGMEM = 26;
const int b3 PROGMEM = 27;
const int menu_right PROGMEM = 28;
const int b4 PROGMEM = 29;
const int menu_run PROGMEM = 30;
const int manual_swtiches_enable PROGMEM = 31;                        // Controls power to manual switches via MOSFET
const int adam6017_power PROGMEM = 32;                                // Power kill switch to ADAM modules
const int b5 PROGMEM = 33;
const int adam6050_power PROGMEM = 34;
const int b6 PROGMEM = 35;
const int latency_led PROGMEM = 36;
const int b7 PROGMEM = 37;
const int adam_do_0 PROGMEM = 38;                                    // Input to read when ADAM DO triggers relay 
const int b8 PROGMEM = 39;
// ethernet pin 50
// ethernet pin 51
// ethernet pin 52
const int a1_in PROGMEM = A4;
const int a2_in PROGMEM = A5;
const int s1_in PROGMEM = A8;                                         // Speed signal 1 in
const int s2_in PROGMEM = A9;
const int s3_in PROGMEM = A10;
const int s4_in PROGMEM = A11;
const int s5_in PROGMEM = A12;
const int s6_in PROGMEM = A13;
const int s7_in PROGMEM = A14;
const int s8_in PROGMEM = A15;

const int input_pins[] PROGMEM = { menu_left, menu_up, menu_down, menu_right, menu_run, adam_do_0 };                                                       // Inputs are menu buttons and start/stop program button, ADAM module digital outputs

const int output_pins[] = {b1, b2, b3, b4, b5, b6, b7, b8, s1_out, s2_out, s3_out, s4_out, s5_out, s6_out, s7_out, s8_out, a1_out, a2_out};       // Outputs are brake and speed signals and analog
const int pots[] = {s1_in, s2_in, s3_in, s4_in, s5_in, s6_in, s7_in, s8_in, a1_in, a2_in};                                                        // Speed signal measurement potentiometers

// Variables 
int mode = 0;                                                                         // Program mode = 0, manual mode = 1, latency test manual = 2, latency test automatic = 3
volatile bool menu_flag = false;                                                      // true when any button is pressed
bool program_run = false;                                                             // Stop program as default
int program_number = 0;                                                               // Current program number
unsigned long program_speed = 1000;                                                   // 1000 placeholder. Program will have this value
bool program_loop = false;
bool latency_run = false;                                                             // Run latency test

// SD card program data variables
char data_step_0[38];                                                                 // Initailize variables
char data_step_1[38];
char data_step_2[38];
char data_step_3[38];
char data_step_4[38];
char data_step_5[38];
char data_step_6[38];
char data_step_7[38];
char data_step_8[38];
char data_step_9[38];
char data_step_10[38];
char data_step_11[38];
char data_step_12[38];
char data_step_13[38];
char data_step_14[38];
char data_step_15[38];
char data_step_16[38];
char data_step_17[38];
char data_step_18[38];
char data_step_19[38];

char description[100] = {"Hello World"};                                                        // 100 char limit *** can maybe be increased, need to test

// Array of step data
char* data[] = { data_step_0, data_step_1, data_step_2, data_step_3, data_step_4, data_step_5, data_step_6, data_step_7, data_step_8, data_step_9,
        data_step_10, data_step_11, data_step_12, data_step_13, data_step_14, data_step_15, data_step_16, data_step_17, data_step_18, data_step_19 };
//int data_steps = sizeof(data) / sizeof(data[0]);                      // Calculate this in SD function
int data_steps;
// declare data array as char* data[100], 100 may be overkill, desktop app will determine max number of steps in program

// char program_list[300] = {"00-01-"};                                                // Array to store file names
char program_list_sorted[100][7];                                                  // Array to store sorted file names
String program_list_string = "";

typedef enum menu_button_pressed {left, up, down, right} menu_button_pressed;       // Menu button options

LiquidCrystal_I2C lcd(0x3F, 20, 4);                                                 // LCD address = 0x3F. 20x4 LCD

File my_file;

String readString;                                                                  // Ethernet variables
byte mac[] = {0xA8, 0x61, 0x0A, 0xAE, 0x83, 0xB1};                                  // Must be unique for each GPIO box Arduino
IPAddress ip(192, 168, 0, 116);                                                     // Must be unique for each GPIO box Arduino
EthernetServer server(80);                                                          // (port 80 is default for HTTP):

EthernetClient client_null;                                                         // Update html without client

#line 134 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void setup();
#line 211 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void loop();
#line 222 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_running();
#line 268 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_layer_1_selection(int index);
#line 297 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_mode_selection(int index);
#line 324 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_program_number(int program_num);
#line 369 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_program_speed(int program_spd, bool refresh);
#line 381 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_loop_mode();
#line 394 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void menu();
#line 728 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
int menu_read_button_pressed();
#line 751 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void switch_mode();
#line 769 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void manual_mode();
#line 787 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void program_mode();
#line 868 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
int calibrate_output(int val);
#line 889 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_manual();
#line 899 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_automatic();
#line 913 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_test();
#line 937 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_running_state();
#line 948 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_no_response();
#line 955 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_result(long time);
#line 963 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void output_reset();
#line 974 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void SD_write();
#line 1047 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void SD_read(int program_num);
#line 1138 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void menu_pressed();
#line 1142 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void ethernet();
#line 1195 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void decode_ethernet(EthernetClient client);
#line 1350 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void update_html(EthernetClient client, int page, int count);
#line 1631 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void list_files(EthernetClient client, bool print);
#line 1691 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void sorted_files_list();
#line 1807 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
int CompareStrings(const void *p1, const void *p2);
#line 1812 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void delete_program();
#line 1849 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void load_program(EthernetClient client);
#line 1884 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
bool lcd_overwrite_program(String program);
#line 1934 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
float map_float(float x, float in_min, float in_max, float out_min, float out_max);
#line 134 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void setup() {
  Serial.begin(9600);
  delay(500);                                                                       // Wait for serial to begin. while(!Serial) not working...

  digitalWrite(adam6017_power, HIGH);                                             // Power on Adam moudules
  digitalWrite(adam6050_power, HIGH);

  digitalWrite(manual_swtiches_enable, LOW);                                      // Disable manual brake switches 

  digitalWrite(latency_led, LOW);                                                 // Ensure latency LED is off at start up

  Ethernet.begin(mac, ip);                                                        // start the Ethernet connection and the server:
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {                          // Check for Ethernet hardware present
    debugln("Ethernet shield was not found.  Sorry, can't run without hardware");
    while (1){}
  }
  server.begin();                                                                 // start Arduino server
  debug("server is at ");
  debugln(Ethernet.localIP());

  lcd.init();                                                                       // Initialize LCD display
  lcd.backlight();                                                                  // Print start up display
  #if DEBUG == 0
    lcd.setCursor(0, 0);
    char title1[9] = "GPIO Box";
    for (int i = 0; i < 8; i++) {
      lcd.print(title1[i]);
      delay(100);
    }
    delay(300);
    lcd.setCursor(0, 2);
    char title2[14] = "Papertech INC";
    for (int i = 0; i < 13; i++) {
      lcd.print(title2[i]);
      delay(100);
    }
    delay(300);
    lcd.setCursor(0, 3);
    char title3[16] = "CORKERY DESIGNS";
    for (int i = 0; i < 15; i++) {
      lcd.print(title3[i]);
      delay(100);
    }
    lcd.clear();                                                                  // END LCD START UP DISPLAY
  #endif

  if (!SD.begin(4)) {                                                             // Initialize SD card
    lcd.print(F("SD Initialization"));
    lcd.setCursor(0, 1);
    lcd.print(F("Failed. Try Reboot"));
    debugln("SD failed");
    while (1);
  }

  SD_read(0);                                                                     // Load default program 

  for (int i = 0; i < sizeof(output_pins)/sizeof(output_pins[0]); i++) {      // Set all digital outputs
    pinMode(output_pins[i], OUTPUT);
  }
  for (int n = 0; n < sizeof(input_pins)/sizeof(input_pins[0]); n++) {        // Set all digital inputs
    pinMode(input_pins[n], INPUT);
  }
  pinMode(manual_swtiches_enable, OUTPUT);

  output_reset();                                                                 // Ensure outputs are disabled

  list_files(client_null, false);
  debugln(program_list_string);

  // readString.reserve(1000);

  attachInterrupt(digitalPinToInterrupt(menu_interrupt), menu_pressed, RISING);   // Menu buttons external interrupt

  delay(2000);                                                                    // Leave start up message for 2 seconds
  lcd_update_running();                                                           // Update LCD
}                                                                                 // END SETUP()

void loop() {
  if (menu_flag) menu();                                                          // Execute menu funciton when external interrupt flag is true

  if (mode == 0) program_mode();                                                  // Execute active mode  
  else if (mode == 1) manual_mode();
  else if (mode == 2) latency_manual();
  else if (mode == 3) latency_automatic();

  ethernet();
}

void lcd_update_running() {                                                       // LCD menu for normal running operation
  switch (mode) {
  case 0:
    lcd.clear();
    lcd.print(F("Mode:        PROGRAM"));
    lcd.setCursor(0, 1);
    lcd.print(F("Program #:        "));
    if (program_number < 10) lcd.print(" ");
    lcd.print(program_number);
    lcd.setCursor(0, 2);
    lcd.print(F("Interval:    "));
    if (program_speed < 1000) lcd.print(F(" "));
    lcd.print(program_speed);
    lcd.print(F(" ms"));
    lcd.setCursor(0, 3);
    lcd.print(F("Loop Mode:    "));
    if (program_loop){
      lcd.setCursor(17, 3);
      lcd.print(F("YES"));
    }
    else{
      lcd.setCursor(18, 3);
      lcd.print(F("No"));
    }
    break;
  case 1:
    lcd.clear();
    lcd.print(F("Mode: MANUAL"));
    break;
  case 2:
    lcd.clear();
    lcd.print(F("Mode: LATENCY MANUAL"));
    lcd.setCursor(0,1);
    lcd.print(F("ADAM 6050 DO 0"));
    latency_running_state();                                          // Update LCD display 
    break;
  case 3:
    lcd.clear();
    lcd.print(F("Mode: LATENCY AUTO"));
    lcd.setCursor(0,1);
    lcd.print(F("ADAM 6050 DO 0"));
    latency_running_state();                                          // Update LCD display 
    break;
  }
}

void lcd_update_layer_1_selection(int index) {                        // LCD first layer menu
  lcd.clear();
  lcd.print(F("Change Mode"));
  if (index == 0) {
    lcd.setCursor(19, 0);
    lcd.print(F("*"));
  }
  if (mode == 0) {
    lcd.setCursor(0, 1);
    lcd.print(F("Change Program"));
    if (index == 1) {
      lcd.setCursor(19, 1);
      lcd.print(F("*"));
    }
    lcd.setCursor(0, 2);
    lcd.print(F("Edit Program Speed"));
    if (index == 2) {
      lcd.setCursor(19, 2);
      lcd.print(F("*"));
    }
    lcd.setCursor(0, 3);
    lcd.print(F("Loop Mode"));
    if (index == 3) {
      lcd.setCursor(19, 3);
      lcd.print(F("*"));
    }
  }
}

void lcd_update_mode_selection(int index) {                         // LCD mode selection menu
  lcd.clear();
  lcd.print(F("PROGRAM"));
  if (index == 0) {
    lcd.setCursor(19, 0);
    lcd.print(F("*"));
  }
  lcd.setCursor(0, 1);
  lcd.print(F("MANUAL"));
  if (index == 1) {
    lcd.setCursor(19, 1);
    lcd.print(F("*"));
  }
  lcd.setCursor(0, 2);
  lcd.print(F("LATENCY MANUAL"));
  if (index == 2) {
    lcd.setCursor(19, 2);
    lcd.print(F("*"));
  }
  lcd.setCursor(0, 3);
  lcd.print(F("LATENCY AUTO"));
  if (index == 3) {
    lcd.setCursor(19, 3);
    lcd.print(F("*"));
  }
}

void lcd_update_program_number(int program_num) {
  lcd.clear();
  lcd.print(F("Choose Program"));
  lcd.setCursor(18, 0);
  String str = program_list_sorted[program_num];
  str = str.substring(0,2);
  lcd.print(str);

  str.concat(".txt");
  my_file = SD.open(str);
  int lines = 0;
  String last_line;
  while (my_file.available()){
    char val = my_file.read();
    if (val == '\n') last_line = "";
    else if (val != '+') last_line += val;                                        // Replace + signs with space
    else last_line += ' ';
  }

  lcd.setCursor(0, 1);
  if (last_line.length() <= 20) lcd.print(last_line);
  else if (last_line.length() <= 40){
    lcd.print(last_line.substring(0,20));
    lcd.setCursor(0,2);
    lcd.print(last_line.substring(20));
  }
  else if (last_line.length() <= 60){
    lcd.print(last_line.substring(0,20));
    lcd.setCursor(0,2);
    lcd.print(last_line.substring(20,40));
    lcd.setCursor(0,3);
    lcd.print(last_line.substring(40));
  }
  else{
    lcd.print(last_line.substring(0,20));
    lcd.setCursor(0,2);
    lcd.print(last_line.substring(20,40));
    lcd.setCursor(0,3);
    lcd.print(last_line.substring(40,57));
    lcd.print(F("..."));
  }
  
  my_file.close();
}

void lcd_update_program_speed(int program_spd, bool refresh) {
  if (refresh) {
    lcd.clear();
    lcd.print(F("Edit Program Speed"));
  }
  lcd.setCursor(0, 1);
  lcd.print(program_spd);
  if (program_spd < 1000) lcd.print(F(" "));
  else if (program_spd < 100) lcd.print(F("  "));
  else if (program_spd < 10) lcd.print(F("   "));
}

void lcd_update_loop_mode(){
  lcd.clear();
  lcd.print(F("Loop Mode:"));
  if (program_loop){
  lcd.setCursor(17, 0);
  lcd.print(F("YES"));
  }
  else{
  lcd.setCursor(18, 0);
  lcd.print(F("NO"));
  }
}

void menu() {                                       // UI button pressed, execute menu
  // Menu Layers
  // 0 - wake UI
  // 1 - Choose mode, choose program, change program speed
  // 2 - settings for elements in layer 1
  // 3 - Select/enter
  // Start/stop program

  static int index_layer = 0;                                           // Menu layer: Enter menu [0], Mode, Program Number, Program Speed [1], Setting [2], Select/Enter (reset UI) [3]
  static int index_layer_1_option = 0;                                  // Index within menu layer 1
  static int index_layer_2_option = 0;                                  // Index within menu layer 2
  static int menu_button_pressed;                                       // Variable to store the result of enum
  static int mode_selection = 0;                                        // Program mode = 0, manual mode = 1, latency test manual = 2, latency test automatic = 3
  static int program_number_selection = program_number;                 // Selection is the menu memory version of actual variable
  static int program_speed_selection = program_speed;
  static unsigned long btn_pressed = 0;                                 // Track how long the button is held down to change speed. Click change by one, hold to change quickly
  static unsigned long btn_hold_threshold = 100;                        // Time needed to activate button held down for quick variable change
  bool btn_hold_flag = false;                                           // Check if btn was held down or clicked
  int btn_hold_count = 0;                                               // Count how many cycles the btn has been held down for

  if (digitalRead(menu_run)) {                                          // Program Start/Stop button pressed
  switch(mode){
    case 0:
      debugln("Start / Stop Program");
      program_run = !program_run;                                       // Toggle start stop program
      if (!program_run) output_reset();  
      // else digitalWrite(latency_led, HIGH);                             // Turn on LED. Changed latency_led to running_led. Would need to add hardware                               
      break;
    case 2:
      latency_run = true;                                               // Start manual latency test
      break;
    case 3:
      latency_run = !latency_run;                                       // Start/stop automatic latency test
      latency_running_state();                                          // Update LCD display 
      break;
    }
  }
  else {                                                                // Menu button pressed
    switch (index_layer) {
    case 0:                                                             // Layer 0 = Enter menu
      index_layer++;                                                    // Step into next menu layer
      debugln("Change Mode");                                    // Wake UI
      index_layer_1_option = 0;                                         // Reset layer 1 index option
      index_layer_2_option = 0;                                         // Reset layer 2 index option
      program_number_selection = program_number;                        // Reset menu
      program_speed_selection = program_speed;
      lcd_update_layer_1_selection(index_layer_1_option);               // Layer 1 LCD menu
      break;
    case 1:                                                             // Layer 1 = Mode, Program Speed, Program Number
      menu_button_pressed = menu_read_button_pressed();
      switch (menu_button_pressed) {
      case left:
        index_layer--;                                                  // Step into previous menu layer (go back)
        debug("Back to running UI, Mode: ");                     // Reset UI to running information  
        debugln(mode);
        lcd_update_running();                                           // Update LCD running display
        break;
      case up:
        if (index_layer_1_option > 0 && mode ==0) index_layer_1_option--;             // Decrement through options. Only increment option when in program mode. No need to change these settings unless we are in program mode

        if (index_layer_1_option == 0) debugln("CHANGE MODE");
        else if (index_layer_1_option == 1) debugln("CHANGE PROGRAM");
        else if (index_layer_1_option == 2) debugln("CHANGE PROGRAM SPEED");
        lcd_update_layer_1_selection(index_layer_1_option);                           // Layer 1 LCD menu
        break;
      case down:
        if (index_layer_1_option < 3 && mode == 0) index_layer_1_option++;            // Increment through options. Only increment option when in program mode. No need to change these settings unless we are in program mode

        if (index_layer_1_option == 0) debugln("CHANGE MODE");
        else if (index_layer_1_option == 1) debugln("CHANGE PROGRAM");
        else if (index_layer_1_option == 2) debugln("CHANGE PROGRAM SPEED");
        lcd_update_layer_1_selection(index_layer_1_option);                           // Layer 1 LCD menu
        break;
      case right:
        index_layer++;                                                  // Select/Enter. Step into next layer of menu
        switch (index_layer_1_option) {
          case 0:
            if (mode == 0) {
              debugln("Program Mode");                           // Display current mode
              index_layer_2_option = 0;
            }
            else if (mode == 1) {
              debugln("Manual Mode");                           // Display current mode
              index_layer_2_option = 1;
            }
            else if (mode == 2) {
              debugln("Latency Mode Manual");                  // Display current mode
              index_layer_2_option = 2;
            }
            else if (mode == 3) {
              debugln("Latency Mode Automatic");               // Display current mode
              index_layer_2_option = 3;
            }
            lcd_update_mode_selection(index_layer_2_option);          // Update LCD menu
            break;
          case 1:
            debugln(program_number);                           // Display current program number
            lcd_update_program_number(program_number_selection);
            break;
          case 2:
            debugln(program_speed);                            // Display current program speed
            lcd_update_program_speed(program_speed_selection, true);
            break;
          case 3:
            lcd_update_loop_mode();
            break;
        }
        break;
      }
      break;
    case 2:                                                         // Layer 2 = Setting
      menu_button_pressed = menu_read_button_pressed();
      switch (menu_button_pressed) {
      case left:
        index_layer--;                                              // Step into previous menu layer (go back)
        if (index_layer_1_option == 0) debugln("CHANGE MODE");
        if (mode == 0) {
          if (index_layer_1_option == 1) debugln("CHANGE PROGRAM");
          else debugln("CHANGE PROGRAM SPEED");
        }
        lcd_update_layer_1_selection(index_layer_1_option);         // Layer 1 LCD menu
        break;
      case up:
        switch (index_layer_1_option) {                             // Choose mode option = 0, change program = 1, change program speed = 2
        case 0:                                                     // MODE selection
          if (index_layer_2_option > 0) index_layer_2_option--;     // Decrement through options

          switch (index_layer_2_option) {
          case 0:
            debugln("Program Mode");                     
            index_layer_2_option = 0;                               // Mode to select = program
            break;
          case 1:
            debugln("Manual Mode");
            index_layer_2_option = 1;                               // Mode to select = manual
            break;
          case 2:
            debugln("Latency Mode Manual");
            index_layer_2_option = 2;                               // Mode to select = latency mode manual
            break;
          case 3:
            debugln("Latency Mode Automatic");
            index_layer_2_option = 3;                               // Mode to select = latency mode automatic                        
            break;
          }
          debugln(index_layer_2_option);
          lcd_update_mode_selection(index_layer_2_option);          // Update LCD menu
          break;
        case 1:                                                     // PROGRAM NUMBER selection
          btn_pressed = millis();
          while (digitalRead(menu_up)) {
              if (millis() - btn_pressed >= 100) {                  // Increase program number quickly by holding down btn
                // if (program_number_selection < 99) program_number_selection++;
                if (program_number_selection < sizeof(program_list_string)/3) program_number_selection++;
                btn_pressed = millis();
                lcd_update_program_number(program_number_selection);
                btn_hold_flag = true;
              }
          }
          if (!btn_hold_flag) {                                     // Increase program speed once by click
            // if (program_number_selection < 99) program_number_selection++;
            if (program_number_selection < sizeof(program_list_string)/3) program_number_selection++;
            lcd_update_program_number(program_number_selection);
            btn_hold_flag = false;                               // Reset flag
          }
          break;
        case 2:                                                     // PROGRAM SPEED selection
          btn_pressed = millis();
          while (digitalRead(menu_up)) {
            if (btn_hold_count <= 20) {
              if (millis() - btn_pressed >= 100) {                  // Increase program speed quickly by holding down btn. Low speed
                if (program_speed_selection < 9999) program_speed_selection++;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else if (btn_hold_count <= 500) {
              if (millis() - btn_pressed >= 10) {                   // Increase program speed quickly by holding down btn. Medium speed
                if (program_speed_selection < 9999) program_speed_selection++;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else {
              if (millis() - btn_pressed >= 1) {                    // Increase program speed quickly by holding down btn. High speed
                if (program_speed_selection < 9999) program_speed_selection+=10;
                if (program_speed_selection > 9999) program_speed_selection = 9999;      // Avoid going over maximum 
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }     
          }
          if (!btn_hold_flag) {                                     // Increase program speed once by click
            if (program_speed_selection < 9999) program_speed_selection++;
            lcd_update_program_speed(program_speed_selection, false);
            btn_hold_flag = false;                              // Reset flag
          }
          break;
          case 3:
            if (!program_loop) program_loop = true;
            lcd_update_loop_mode();
            break;
        }
        break;
      case down:
        switch (index_layer_1_option) {                           // Choose mode option = 0, change program = 1, change program speed = 2
        case 0:                                                   // MODE selection
          if (index_layer_2_option < 3) index_layer_2_option++;   // Decrement through options

          switch (index_layer_2_option) {
          case 0:
            debugln("Program Mode");
            mode_selection = 0;                                  // Mode to select = program
            break;
          case 1:
            debugln("Manual Mode");
            mode_selection = 1;                                 // Mode to select = manual
            break;
          case 2:
            debugln("Latency Mode Manual");
            mode_selection = 2;                                 // Mode to select = latency mode manual
            break;
          case 3:
            debugln("Latency Mode Automatic");
            mode_selection = 3;                                 // Mode to select = latency mode automatic
            break;
          }
          lcd_update_mode_selection(index_layer_2_option);      // Update LCD menu
          break;
        case 1:                                                 // PROGRAM NUMBER selection
          btn_pressed = millis();
          while (digitalRead(menu_down)) {
              if (millis() - btn_pressed >= 100) {                  // Decrease program number quickly by holding down btn
                if (program_number_selection > 0) program_number_selection--;
                btn_pressed = millis();
                lcd_update_program_number(program_number_selection);
                btn_hold_flag = true;
              }
          }
          if (!btn_hold_flag) {                                     // Decrease program speed once by click
            if (program_number_selection > 0) program_number_selection--;
            lcd_update_program_number(program_number_selection);
            btn_hold_flag = false;                                  // Reset flag
          }
          break;
        case 2:                                                 // PROGRAM SPEED selection
          btn_pressed = millis();
          while (digitalRead(menu_down)) {
            if (btn_hold_count <= 20) {
              if (millis() - btn_pressed >= 100) {                  // Decrease program speed quickly by holding down btn. Low speed
                if (program_speed_selection > 1) program_speed_selection--;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else if (btn_hold_count <= 500) {
              if (millis() - btn_pressed >= 10) {                   // Decrease program speed quickly by holding down btn. Medium speed
                if (program_speed_selection > 1) program_speed_selection--;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else {
              if (millis() - btn_pressed >= 1) {                    // Decrease program speed quickly by holding down btn. High speed
                if (program_speed_selection > 1) program_speed_selection -= 10;
                if (program_speed_selection < 1) program_speed_selection = 1;         // Avoid less than minimum
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
          }
          if (!btn_hold_flag) {                                     // Decrease program speed once by click
            if (program_speed_selection > 1) program_speed_selection--;
            lcd_update_program_speed(program_speed_selection, false);
            btn_hold_flag = false;                                   // Reset flag
          }
          break;
          case 3:
            if (program_loop) program_loop = false;
            lcd_update_loop_mode();
            break;
        }
        break;

      case right:
        switch (index_layer_1_option) {
        case 0:                         
          mode = index_layer_2_option;                              // Updated mode to new selection
          debug("Back to running UI, mode: ");
          debugln(mode);
          lcd_update_running();                                     // Update LCD running display
          switch_mode();
          break;
        case 1:
          program_number = program_number_selection;
          debug("Program number: ");
          debugln(program_number);
          SD_read(program_number);                                  // Load new program
          program_run = false;                                      // Stop running when program changes
          output_reset();
          lcd_update_running();                                     // Update LCD running display
          break;
        case 2:
          program_speed = program_speed_selection;
          debug("Program speed: ");
          debugln(program_speed);
          lcd_update_running();                                     // Update LCD running display
          break;
        case 3:
          lcd_update_running();
        }

        index_layer = 0;
        break;
      }
      break;
    }
  }

  menu_flag = false;                                                // Reset menu flag
}

int menu_read_button_pressed() {
  unsigned long debounce = 0;
  if (digitalRead(menu_left)) {
    return left;                                                    // Left
    delay(debounce);                                                // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_up)) {
    return up;                                                      // Up
    delay(debounce);                                                // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_down)) {
    return down;                                                    // Down
    delay(debounce);                                                // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_right)) {
    return right;                                                   // Right
    delay(debounce);                                                // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_run)) {
    delay(debounce);                                                // Needs a bit of debounce.... (check schmitt trigger)
  }
}

void switch_mode() {
  if (mode == 0) {                                                  // Program mode
    output_reset();                                                 // Reset outputs
    program_run = false;                                            // Program in Stop mode to begin
    SD_read(program_number);                                        // Load current program
  }
  else if (mode == 1) {                                             // Manual mode
    output_reset();                                                 // Reset outputs
    digitalWrite(manual_swtiches_enable, HIGH);                     // Enable manual swtichess
  }
  else if (mode == 2) {                                             // Latency test - manual mode
    output_reset();                                                 // Reset outputs
  }
  else if (mode == 3) {                                             // Latency test - automatic mode
    output_reset();                                                 // Reset outputs
  }
}
  
void manual_mode() {
  static unsigned long manual_time = 0;                             // Current time 
  static unsigned long manual_update = 100;                         // 100ms default. Try different values

  if (millis() - manual_time >= manual_update) {                    // Check if update time has been reached
    for (int i = 0; i < 10; i++) {                                  // 8 speed signals and 2 analog outputs
      int val = analogRead(pots[i]);                                // Read speed/analog signals
      val = map(val, 0, 1023, 35, 255);                             // 35 - 255 gives some buffer at each limit        
      if (val <= 41) val = 0;                                       // 4-20ma -> 1-5V -> 41-243 analog write
      else if (val >= 243) val = 243;  
      analogWrite(output_pins[i + 8], val);                         // Output speed/analog signals
      debug(val);
      debug(" - ");                                                 
    }
    debugln();
  }
}

void program_mode() {                                               // Loop through the number of steps in the program and output brake/speed/analog signals per step in the loop
  const byte wheel_0[] PROGMEM = {B00000,  B01110,  B00001,  B00001,  B10001,  B10001,  B01110,  B00000};
  const byte wheel_1[] PROGMEM = {B00000,  B00010,  B10001,  B10001,  B10001,  B10001,  B01110,  B00000};
  const byte wheel_2[] PROGMEM = {B00000,  B01100,  B10000,  B10001,  B10001,  B10001,  B01110,  B00000};
  const byte wheel_3[] PROGMEM = {B00000,  B01110,  B10001,  B10000,  B10000,  B10001,  B01110,  B00000};
  const byte wheel_4[] PROGMEM = {B00000,  B01110,  B10001,  B10001,  B10001,  B10000,  B01100,  B00000};
  const byte wheel_5[] PROGMEM = {B00000,  B01110,  B10001,  B10001,  B10001,  B10001,  B00010,  B00000};
  const byte wheel_6[] PROGMEM = {B00000,  B01110,  B10001,  B10001,  B00001,  B00001,  B01110,  B00000};
  const byte *wheel[] PROGMEM = {wheel_0, wheel_1, wheel_2, wheel_3, wheel_4, wheel_5, wheel_6};
  static unsigned long program_time = 0;                            // Current time 
  static int step = 0;                                              // Current step in program
  static unsigned long loading_time = millis();
  static bool flip = true;
  static bool do_once = true;
  static int index = 0;

  if (millis() - loading_time >= 800 && program_run){               // LCD running animation
    // flip = !flip;
    // if (flip) {
    //   lcd.setCursor(11, 0);
    //   lcd.print("<");
    // }
    // else{
    //   lcd.setCursor(11, 0);
    //   lcd.print(">");
    // }
    
    lcd.createChar(0, wheel[index]);
    lcd.setCursor(11,0);
    lcd.write(0);

    index++;
    if (index > sizeof(wheel)/sizeof(wheel[0]) - 1) index = 0;

    loading_time = millis();
  }
  else if (!program_run && do_once){                                // Clear symbol once program stops running
    lcd.setCursor(11, 0);
    lcd.print(F(" "));
    do_once = false;
  }

  if (program_run && !do_once) do_once = true;                      // Reset flag
  
  if (program_run) {                                                // Check if START/STOP button is pressed (Run program)
    if (millis() - program_time >= program_speed) {                 // Check if update time has been reached. Time interval can be changed by user via menu, this is an option
      int val_int;
      char val_char[3] = {'0', '0', '0'};
      
      for (int n = 0; n < 8; n++) {                                 // Brake signal digital outputs. Number of brake signals. 
        val_char[2] = data[step][n];                                // Read brake signal from program data
        val_int = atoi(val_char);
        digitalWrite(output_pins[n], val_int);
      }
      for (int m = 0; m < 10; m++) {                                // Speed signal & analog outputs. Number of signals = 10
        for (int p = 0; p < 3; p++) {
          val_char[p] = data[step][p + 3 * m + 8];                  // Read speed signal from program data
        }
        val_int = atoi(val_char);
        debug(val_int);
        debug(" - ");
        val_int = calibrate_output(val_int);
        debugln(val_int);
        analogWrite(output_pins[m + 8], val_int); 
      }

      step++;
      if (step == data_steps) {
        step = 0;           
        if (!program_loop) {
          program_run = false;
          delay(program_speed);         // ****** change to while < speed & !menuflag
          output_reset();
        }
      }
      program_time = millis();
    }
  }
  else step = 0;
}

int calibrate_output(int val){
  if (val < 41) return val;
  else if (41 <= val && val < 51) return val -= 1;
  else if (51 <= val && val < 64) return val -= 2;
  else if (64 <= val && val < 77) return val -= 3;
  else if (77 <= val && val < 89) return val -= 4;
  else if (89 <= val && val < 102) return val -= 6;
  else if (102 <= val && val < 115) return val -= 7; 
  else if (115 <= val && val < 128) return val -= 7;
  else if (128 <= val && val < 140) return val -= 7;
  else if (140 <= val && val < 153) return val -= 8;
  else if (153 <= val && val < 166) return val -= 8;
  else if (166 <= val && val < 179) return val -= 7;
  else if (179 <= val && val < 191) return val -= 7;
  else if (191 <= val && val < 204) return val -= 6;
  else if (204 <= val && val < 217) return val -= 4;
  else if (217 <= val && val < 230) return val -= 2;
  else if (230 <= val && val < 242) return val -= 1;
  else if (val >= 242) return val -= 1;
}

void latency_manual() {
  if (latency_run){                                             // Start test button was pressed
    latency_test();                                             // Run test one time

    latency_run = false;                                        // Reset flag

    latency_running_state();                                    // Update LCD display with "paused"
  }
}

void latency_automatic() {
  static unsigned long offset = random(0, 5000);                // 0 - 5 second delay
  static unsigned long previous_time = millis();

  if (latency_run){                                             // Start test button pressed
    if (millis() - previous_time > 5000 + offset){              // Run test every 5 seconds + random offset time
      latency_test();                                           // Run test

      offset = random(0, 5000);                                 // New random offset
      previous_time = millis();                                 // Record time
    }
  }
}

void latency_test(){
  unsigned long start_time;
  unsigned long latency_time;
  unsigned long timeout = 60000;                                // 60 000ms = 1 min
  bool no_response = false;

  latency_running_state();

  start_time = millis();                                        // Test start time

  digitalWrite(latency_led, HIGH);                              // Turn on LED

  while (millis() - start_time < timeout && digitalRead(adam_do_0) == HIGH){}    // Wait for PTI software to trigger ADAM6050 module or for test to timeout

  latency_time = millis() - start_time;                         // Record test finish time

  if (millis() - start_time >= timeout) no_response = true;

  digitalWrite(latency_led, LOW);                               // Turn off LED

  if (no_response) latency_no_response();                       // LCD display no response
  else latency_result(latency_time);                            // LCD show latency time
}

void latency_running_state(){
  if (latency_run){
    lcd.setCursor(0,3);
    lcd.print(F("RUNNING"));
  }
  else{
    lcd.setCursor(0,3);
    lcd.print(F("PAUSED "));
  }
}

void latency_no_response(){
  lcd.setCursor(0,2);
  lcd.print(F("                    "));
  lcd.setCursor(0,2);
  lcd.print(F("NO RESPONSE"));
}

void latency_result(long time){
  lcd.setCursor(0,2);
  lcd.print(F("Latency:            "));
  lcd.setCursor(9,2);
  lcd.print(time);
  lcd.print(F("ms"));
}

void output_reset() {                                           // Turn off all MOSFET swtiches from program mode, and set speed signals to zero
  for (int i = 0; i < 8; i++) {                                 // 8 brake signals
    digitalWrite(output_pins[i], LOW);                          // Turn of brake signals
  }
  for (int n = 0; n < 10; n++) {                                // 8 speed signals, 2 analog signals
    analogWrite(output_pins[n + 8], 0);                         // Turn off speed signals
  }
  digitalWrite(manual_swtiches_enable, LOW);                    // Disable manual switches
  digitalWrite(latency_led, LOW);                               // Turn on LED
}

void SD_write() {                                               // Write data to SD card
if (program_number != 0){                                       // Program 0 can not be removed
    char file_name[7] = {'0', '0', '.', 't', 'x', 't'};         // Defualt file name
    String str;
    str = String(program_number);                                 // Convert program number to string
    if (program_number < 10) file_name[1] = str[0];               // Update file name 
    else {
      file_name[0] = str[0];
      file_name[1] = str[1];
    }
         
    SD.remove(file_name);                                         // Remove file

    my_file = SD.open(file_name, FILE_WRITE);                     // Create program 0

    if (my_file) {
      my_file.print(file_name[0]);                                // Program #
      my_file.print(file_name[1]);
      my_file.print('\n');

      String prog_speed = "";
      str = String(program_speed);
      if (str.length() == 4) prog_speed = str;
      else if (str.length() == 3){
        prog_speed.concat('0');
        prog_speed.concat(str[0]);
        prog_speed.concat(str[1]);
        prog_speed.concat(str[2]);
      }
      else if (str.length() == 2){
        prog_speed.concat("0");
        prog_speed.concat("0");
        prog_speed.concat(str[0]);
        prog_speed.concat(str[1]);
      }
      else {
        prog_speed.concat("0");
        prog_speed.concat("0");
        prog_speed.concat("0");
        prog_speed.concat(str[0]);
      }
      debugln(prog_speed);
      my_file.print(prog_speed);                                  // Program speed. Step time [ms]
      my_file.print('\n');

      for (int i = 0; i < data_steps; i++){                       // Step data
        for (int x = 0; x < 38; x++){
          my_file.print(data[i][x]);
        }
        my_file.print('\n');
      }

      my_file.print('\n');
      my_file.print(description);                                // Program description
      
      my_file.close();

      debugln("program saved to SD");
    }
    else {
      debugln("Failed to save program to SD");
    } 
  }
  else{
    lcd.clear();
    lcd.print(F("PROGRAM 0 CAN"));
    lcd.setCursor(0,1);
    lcd.print(F("NOT BE MODIFIED"));
    delay(2000);
    lcd_update_running();
  }
}

void SD_read(int program_num) {                               // Read and process data. program_number = selcted program (1, 2, 3....)
  char file_name[7] = {'0', '0', '.', 't', 'x', 't'};         // Defualt file name
  String str;
  str = String(program_num);                                  // Convert program number to string
  if (program_num < 10) file_name[1] = str[0];                // Update file name 
  else {
    file_name[0] = str[0];
    file_name[1] = str[1];
  }

  debug("File name = ");
  debugln(file_name);

  my_file = SD.open(file_name);                               // Open selected program number
  if (my_file) {
    bool meta_info = true;
    int SD_step = 0;                                          // Current step being read by SD card. What line (row) in txt file
    int index = 0;                                            // Current index within step array
    char val;                                                 // Val to store incoming char
    data_steps = 0;                                           // Reset the number of steps in current program
    char program_num_char[2] = {};                            // Read and save program number. First two bytes in file
    char program_spd_char[4] = {};                            // Read and save program number. First two bytes in file
    bool new_line = false;

    while (my_file.available()) {
      val = my_file.read();                                   // Read next byte from txt file
      if (val != '\n') {                                      // Read data line by line and save data as steps
        if (SD_step == 0) {                                   // Save program number data
          program_num_char[index] = val;
          index++;
        }
        else if (SD_step == 1) {                              // Save program speed data
          program_spd_char[index] = val;
          index++;
        }
        else {                                                // Save step data data
          data[data_steps][index] = val;
          index++;
        }
        new_line = false;
      }
      else if (new_line){                                     // Blank line was read, this indicates end of data, start of description
        index = 0;
        while (my_file.available()){                          // Read the rest of the file
          val = my_file.read();
          if (val == '+') val = ' ';
          description[index] = val;
          index++;
        }
        debugln("description:");
        debugln(description);
        break;
      }
      else {                                    // New line reached
        new_line = true;

        debug(SD_step);
        debug("  ");

        if (SD_step == 0) {
          program_number = atoi(program_num_char);            // Convert data to int
          debugln(program_number);
        }
        else if (SD_step == 1) {
          program_speed = atoi(program_spd_char);             // Convert data to int
          debugln(program_speed);
        }
        else {
          #if DEBUG == 1
            for (int w = 0; w < 38; w++) debug(data[data_steps][w]);
            debugln(" ");
          #endif
          data_steps++;
        }
        SD_step++;                                                // Advance to next line on SD card
        index = 0;                                                // Reset "cursor" to first value of SD line
      }
    }
    my_file.close();
    debug("Number of steps in program: ");
    debugln(data_steps);
  }
  else {
    lcd.clear();
    lcd.print(F("Program Not Found"));
    delay(3500);
    SD_read(0);                                                 // Error, so load default program
  }
  lcd_update_running();                                         // Update LCD
}

void menu_pressed() {                                           // External interrupt triggered when any menu or start/stop button is pressed
  menu_flag = true;
}

void ethernet(){
  EthernetClient client = server.available();                   // listen for incoming clients
  
  if (client) {
    debugln("new client");

    boolean currentLineIsBlank = true;                          // an http request ends with a blank line
    
    debugln("");
    debug("start of readString");
    int index = 0;
    readString = "";                                            // Reset readString
    while (client.available()) {
      char c = client.read();
      #if DEBUG == 1 
        Serial.write(c);
      #endif

      if (index > 595) readString += c;                         // Store incoming data from http client. Start after HTML data
      // if (index > 450) readString += c;                         // Store incoming data from http client. Start after HTML data

      if (c == '\n' && currentLineIsBlank) {                    // if you've gotten to the end of the line (received a newline character) and the line is blank, the http request has ended, so you can send a reply
        client.println("HTTP/1.1 200 OK");                      // send a standard http response header
        client.println("Content-Type: text/html");
        // client.println("Connection: keep-alive");
        client.println("Connection: close");
        client.println();
        // print favicon
      }
      
      else if (c == '\n') {
        currentLineIsBlank = true;                              // you're starting a new line
      } 
      else if (c != '\r') {
        currentLineIsBlank = false;                             // you've gotten a character on the current line
      }

      index++;
    }
    debug("end of readstring ");
    debug("readString = ");
    debugln(readString);
    debug("length of readString = ");
    debugln(readString.length());
    debugln(index);

    decode_ethernet(client);                                    // Decode readString

    readString = "";                                            // Reset readString
  }
  client.stop();                                                // Disconnect from client
}

void decode_ethernet(EthernetClient client){
  debug("start of decode ethernet ");

  static bool first_html = true;                                              // Load main.html the first time the client is connected
  bool save_flag;

  const String step_names[] PROGMEM = { "step_0_data", "step_1_data", "step_2_data", "step_3_data", "step_4_data", "step_5_data", "step_6_data", "step_7_data", "step_8_data", "step_9_data",
        "step_10_data", "step_11_data", "step_12_data", "step_13_data", "step_14_data", "step_15_data", "step_16_data", "step_17_data", "step_18_data", "step_19_data" };

  if (first_html) {
    debugln("first html load");
    update_html(client, 0, 0);                                                // Load main.html
    first_html = false;                                                       
    return;
  }

  if (readString.indexOf("program=") > 0){                                    // Read the program number being uploaded from html page
    int index = readString.indexOf("program=");
    String val = readString.substring(index + 8, index + 8 + 2);              // 8 = length of "program=" string
    if (val[0] != '&') {                                                      // Check if number was saved. & = no number in input box
      if (val[1] == '&'){                                                     // Val < 10. ex 1 -> 1&
        val[1] = val[0];                                                      // convert val 1& -> 01
        val[0] = '0';
      }
      program_number = val.toInt();
      debugln(" ");
      debug("Program # uploaded: ");  
      debugln(program_number);  

      if (program_number == 0) return;                                        // Can not edit program 0, defualt program

      char file_name[7] = {val[0], val[1], '.', 't', 'x', 't'};               // File name with selected program number
      my_file = SD.open(file_name);
      if (my_file){                                                           // check if program # already exists on SD card
        // save_flag = lcd_overwrite_program(val);                               // if exisits, overwrite yes/no?. Choice is made on html ui
        save_flag = true;
      }
      else {
        debugln("File does not exist");
        save_flag = true;
      }
      
      if (!save_flag){                                                        // no -> update html to show no save
        debugln("Save file? No selected");
      }
    }
    else {                                                                    // No number was in html input box
      save_flag = false;                                                 
      debugln("No program # selected");    
    }                
             

    if (save_flag){                                                               // if continue flag, proceed with for loop below
      if (readString.indexOf("speed=") > 0){                                      // Extract speed value
        int index = readString.indexOf("speed=");
        String val = readString.substring(index + 6, index + 6 + 4);              // 6 = length of "speed=" string
        if (val[0] != '&') {                                                      // Check if number was saved. & = no number in input box
          if (val[1] == '&'){                                                     // Val < 10. ex 1 -> 1&
            val[3] = val[0];                                                      // convert val 1&tp -> 0001
            val[2] = '0';
            val[1] = '0';
            val[0] = '0';
          }
          else if (val[2] == '&'){                                                // 10 < Val < 100. ex 10 -> 10&
            val[3] = val[1];
            val[2] = val[0];                                                      // convert val 10&s -> 0010
            val[1] = '0';
            val[0] = '0';
          }
          else if (val[3] == '&'){                                                // 100 < Val < 1000. ex 100& -> 0100
            val[3] = val[2];
            val[2] = val[1];
            val[1] = val[0];                                                      // convert val 10& -> 0100
            val[0] = '0';
          }
          program_speed = val.toInt();
          debugln("");
          debug("Program speed uploaded: ");  
          debugln(val);  
        }
        else program_speed = 1000;                                              // No speed inputed, default to 1000ms step time
      }

      data_steps = 0;                                                           // Reset step count. New program will be loaded
      for (int i = 0; i < 20; i++){                                             // Loop through all possible steps from html page
        if (readString.indexOf(step_names[i]) > 0){                             // > 0 if data exists
          int index = readString.indexOf(step_names[i]);
          String val = readString.substring(index + 12, index + 12 + 38);       // 12 = length of "step_x_data=" string
          for (int x = 0; x < 38; x++){                                         // Save data to data_step_i variables
            data[i][x] = val[x];
            debug(data[i][x]);
          }
          debugln(" ");
          data_steps++;                                                         // Increase step count
        }
      }

      if (readString.indexOf("description=") > 0){                              // Extract program description
        int index = readString.indexOf("description=");
        String val = readString.substring(index + 12, readString.indexOf("program=")-1); // 12 = length of "description=" string
        for (int i = 0; i < 100; i++){                                          // Reset the description
          description[i] = '\0';
        }
        for (int i = 0; i < val.length(); i++){                                 // Copy description received from client
          description[i] = val[i];
        }
        debugln(description);
      }

      SD_write();                                                               // Save program to SD card. SD_write()
      SD_read(program_number);                                                  // Read and load new program

      list_files(client_null, false);                                           // Update program list
      debugln(program_list_string);
    }

    debugln(" ");
    debugln("loading : main.html");
    update_html(client, 0, 0);                                                  // Update html with current program settings
  }

  else if (readString.indexOf("list_form=") > 0){ 
    debugln(" ");
    debugln("loading : list.html");
    update_html(client, 1, 0);                                                  // Load list.html 
  }
  else if (readString.indexOf("load_main=") > 0){ 
    debugln(" ");
    debugln("loading : main.html");
    list_files(client_null, false);                                             // Update program list
    update_html(client, 0, 0);                                                  // Load list.html 
    debug("program list string = ");
    debugln(program_list_string);
  }
  else if (readString.indexOf("program_load=") > 0){                            // Update descriptions from list.html page
    debugln(" ");
    debugln("Check if program exists and load program");
    list_files(client_null, false);                                             // Update program list
    load_program(client);                                                       // Load selected program
  }
  else if (readString.indexOf("delete=") > 0){                                  // Delete selected program
    debugln(" ");
    debugln("Delete program");  
    debugln(readString);
    delete_program();
    list_files(client_null, false);
    if (readString.indexOf("list=") > 0) update_html(client, 1, 0);             // Delete called from SAVED PROGRAMS page
    else update_html(client, 0, 0);                                             // Delete called from main page
  }
  else{
    update_html(client, 0, 0);                                                  // Load main.html, page refesh
  }
  debug("end of decode ethernet ");
}

void update_html(EthernetClient client, int page, int count){
  debug("pre updat html : ");
  if (page == 0){                                                 // main.html
    my_file = SD.open("htmlA.txt");                                // open html file
    if (my_file){
      debugln("htmlA file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      debugln("html a closed");
      my_file.close();
    }
    else debugln("htmlA failed to open");
    // get sorted list of saved files
    // print list to hidden text input
    // print number followed by - ie 01-02-...
    // list_files(client_null, false);
    client.print(program_list_string);
    //
    my_file = SD.open("htmlB.txt");                                // open html file
    if (my_file){
      debugln("htmlB file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      debugln("html b closed");
      my_file.close();
    }
    else debugln("htmlB failed to open");
  }
  else if (page == 1){                                            // list.html        list of saved programs
    my_file = SD.open("list1.txt");                               // open start half html file
    if (my_file){
      debugln("list1.html file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("list1.html failed to open");

    // print file names and descriptions
    list_files(client, true);

    my_file = SD.open("list2.txt");                               // open second half html file
    if (my_file){
      debugln("list2.html file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("list2.html failed to open");
  }
  else if (page == 2){                                            // Load program
    my_file = SD.open("html1.txt");                               // open html file
    if (my_file){
      debugln("html1 file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("html1 failed to open");
    // Program nuber
    client.print(readString.substring(0,2));                      // Program number
    //
    my_file = SD.open("html2.txt");                               // open html file
    if (my_file){
      debugln("html2 file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("html2 failed to open");
    // program speed
    client.print(readString.substring(3,7));
    //
    my_file = SD.open("html3.txt");                               // open html file
    if (my_file){
      debugln("html3 file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("html3 failed to open");
    // step data ui
    for (int i = 0; i < count - 4; i++){                          // 4 lines are program number, speed, blank, description
      client.print("<div class='step'>");
      client.print("<div class='step_label'>");
      client.print(i);
      client.print("</div>");

      int index = 8 + i*39;                                       // First char in line
      for (int a = 0; a < 8; a++){
        client.print("<div><input type='checkbox'");
        if (readString[index + a] == '1') client.print(" checked ");
        client.print("></div>");
      }       
      for (int b = 0; b < 10; b++){
        client.print("<div><input type='number' value='");
        String str = readString.substring(index + 8 + 3*b, index + 8 + 3*b + 3);
        float val = str.toFloat();
        val = map_float(val, 41, 242, 4, 20);
        if (val < 4) val = 0;
        if (val == 0) client.print('0');
        else client.print(val, 1);
        client.print("' onchange='limit_break(this)'></div>");
      }

      client.print("</div>");
    }
    //
    my_file = SD.open("html4.txt");                               // open html file
    if (my_file){
      debugln("html4 file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("html4 failed to open");
    // Description
    bool first = false;                                           // first '\n' , end of file -> '\n' '\n' description
    int index2 = 0;                                               // current char index in readString. Looking for first char in last line
    unsigned long time_out = millis();
    while(1){                                                     // Find index of first char in last line
      char val2 = readString[index2];
      if (val2 != '\n') {
        index2++;
        first = false;
      }
      else if (val2 == '\n' && first == false) {                  // New line
        index2++;
        first = true;
      }
      else if (val2 == '\n' && first == true) {                   // Last line       
        index2++;
        break;
      }
      if (millis() - time_out >= 9999){
        debugln("html load description timed out");
        break;
      }
    }
    String str = readString.substring(index2);
    str.replace('+',' ');                                         // Remove all + symbols
    client.print(str);                                            // Print last line
    //
    my_file = SD.open("html5.txt");                               // open html file
    if (my_file){
      debugln("html5 file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("html5 failed to open");
    // step_data_x hidden 
    client.print(readString.substring(0,2));                      // Program nuber
    client.print("'>");

    client.print("<input type='text' id='speed' class='hidden' name='speed' value='");    
    client.print(readString.substring(3,7));                      // Program speed
    client.print("'>");


    for (int i = 0; i < count - 4; i++){                          // 4 lines are program number, speed, blank, description
      client.print("<input id='form_data' type='text' name='step_");
      client.print(i);
      client.print("_data' value='");

      int index = 7 + i*39;                                       // First char in line
      for (int i = 0; i < 38; i++) client.print(readString[index + i]);
      

      client.print("' class='hidden'>");
    }
    //
    my_file = SD.open("html6.txt");                               // open html file
    if (my_file){
      debugln("html6 file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("html6 failed to open");
    // Program list
    // client.print(program_list);                   // TEST data
    client.print(program_list_string);  
    //
    my_file = SD.open("html7.txt");                               // open html file
    if (my_file){
      debugln("html7 file opened");
      while(my_file.available()){                                 // Read html file
        char val;
        val = my_file.read();
        client.print(val);                                        // Write html content to browser
      }
      my_file.close();
    }
    else debugln("html7 failed to open");
  }
  debug("post updat html : ");
}



// void list_files(EthernetClient client, bool print) {              // print = true -> print html content to client. False -> created sorted list
//   my_file = SD.open("/");
//   program_list_string = "";
//   while (true){
//     File entry =  my_file.openNextFile();
//     if (! entry) break;                                           // no more files

//     if (print){
//       char *str = entry.name();
//       if (isDigit(str[0])){                                       // Do not read HTML, LIST files, etc. Only program files
//         client.print(F("<form><input type='submit' value='Load'><input type='button' value='Delete' onclick='delete_program(this.parentNode)''><label>"));
//         client.print(str[0]);
//         client.print(str[1]);
//         client.print(F("</label><label>"));

//         int index = 0;
//         memset(description, '\0', sizeof(description));
//         while (entry.available()){                                // Extract description from current entry
//           char val = entry.read();
//           if (val != '\n') {                                      // Read next char
//             if (val == '+') val = ' ';
//             description[index] = val;                             // Once last line is read, that will be the description
//             index++;                                              // Go to next line
//           }
//           else {
//             index = 0;
//             memset(description, '\0', sizeof(description));
//           }
//         }
//         client.print(description);
//         client.print(F("</label><input class='hidden' type='text' value='"));
//         client.print(str[0]);
//         client.print(str[1]);
//         client.print(F("' name='program_load'></form>"));
//       }
//     }
//     else {
//       // debugln(entry.name());                                     // Print list of files to serial monitor
//       if (isDigit(entry.name()[0])) {
//         char *str = entry.name();
//         program_list_string += str[0];
//         program_list_string += str[1];
//         program_list_string += "-";
//       }
//       // sorted_files_list();
//     }
//     entry.close();
//   }
// }

void list_files(EthernetClient client, bool print) {              // print = true -> print html content to client. False -> created sorted list
  int index_file = 0;

  program_list_string = "";

  sorted_files_list();

  debugln("list files function start");
  // File root = SD.open("/");
  while (true){
    my_file = SD.open(program_list_sorted[index_file]);
    // my_file = root.openNextFile();
    
    debugln(String(program_list_sorted[index_file]));
    if (!my_file) break;                                           // no more files

    if (print){
      if (isDigit(my_file.name()[0])){                             // Do not read HTML, LIST files, etc. Only program files
        char *str = my_file.name();
        
        client.print(F("<form method='post' action='/''><input type='submit' value='Load'><input type='button' value='Delete' onclick='delete_program(this.parentNode)''><label>"));
        client.print(str[0]);
        client.print(str[1]);
        client.print(F("</label><label>"));

        int index = 0;
        memset(description, '\0', sizeof(description));
        while (my_file.available()){                              // Extract description from current entry
          char val = my_file.read();
          if (val != '\n') {                                      // Read next char
            if (val == '+') val = ' ';
            description[index] = val;                             // Once last line is read, that will be the description
            index++;                                              // Go to next line
          }
          else {
            index = 0;
            memset(description, '\0', sizeof(description));
          }
        }
        client.print(description);
        client.print(F("</label><input class='hidden' type='text' value='"));
        client.print(str[0]);
        client.print(str[1]);
        client.print(F("' name='program_load'></form>"));
      }
    }
    else {
      if (isDigit(my_file.name()[0])) {                         // Add program numbers only to string of program numbers. HTML file uses this string
        char *str = my_file.name();
        program_list_string += str[0];
        program_list_string += str[1];
        program_list_string += "-";
      }
    }
    my_file.close();
    index_file++;
  }
  // root.close();
}

void sorted_files_list(){
  debugln("start of sort function");
  debug("start of sort function ");

  int max_files = 113;                                        // 101 +  number of html css etc files (12)
  int index = 0;                                 
  int elementCount = 0;                                       // Number of elements in program_list_sorted

  for (int n = 0; n < sizeof(program_list_sorted)/sizeof(program_list_sorted[0]); n++) program_list_sorted[n][0] = '\0';      // Reset the array to null

  File root = SD.open("/");                                   // Open root directory
  if (root){
    debugln("root opened");

    while (index < max_files){   
    File entry = root.openNextFile();                         // Loop through files on SD card

    // if (!strlen(str)) {
    if (!entry) {
      break;                                                  // No more files                                                  
    }

    char *str = entry.name();                                 // Save file name pointer

    if (!isDigit(str[0])) {                                   // Don't include html css etc files in sorted list
      entry.close();
      continue;                                               
    }

    strcpy(program_list_sorted[index], str);                  // Save file name to program_list_sorted
    
    debugln("entry closed");
    entry.close();                                            // Close file
    index++;
    }
  
    if (index == max_files)
    {
      debugln("too many files");                              // Alert user of error
    }
    else
    {
      elementCount = index;                                   // Count number of elements in myWords
    
      qsort(program_list_sorted, elementCount, sizeof(program_list_sorted[0]), CompareStrings);      // Sort elements
      #if DEBUG
        debugln("Sorted list");
        for (int i = 0; i < elementCount; i++) {
          debugln(program_list_sorted[i]);                    // Print sorted elements
        }
      #endif
    }

    debugln("file closed / end of sorting function");
    root.close();
  }
  else debugln("failed to open root");

  debug("end of sort function ");
}

// void sorted_files_list(){
//   debugln("start of sort function");
//   int max_files = 113;                                        // 101 +  number of html css etc files (12)
//   int index = 0;                                 
//   int elementCount = 0;                                       // Number of elements in program_list_sorted

//   my_file = SD.open("/");                                     // Open root directory
//   if (!my_file) debugln("failed to open root");
//   // my_file.rewindDirectory();
  
//   while (index < max_files){   
//     // my_file = SD.open("/");
//     File entry = my_file.openNextFile();                      // Loop through files on SD card
//     if (!entry) break;
    
//     char *str = entry.name();                                 // Save file name pointer

//     if (!strlen(str)) {
//       // my_file.rewindDirectory();  
//       break;                                                  // No more files                                                  
//     }

//     if (!isDigit(str[0])) {                                   // Don't include html css etc files in sorted list
//       elementCount++;
//       continue;                                               
//     }
    
//     strcpy(program_list_sorted[index], str);                  // Save file name to program_list_sorted
    
//     debugln("entry closed");
//     entry.close();                                            // Close file
//     // my_file.close();
//     index++;
//   }
  
//   if (index == max_files)
//   {
//     debugln("too many files");                                // Alert user of error
//   }
//   else
//   {
//     // elementCount = index;                                     // Count number of elements in myWords
  
//     qsort(program_list_sorted, elementCount, sizeof(program_list_sorted[0]), CompareStrings);      // Sort elements
//     #if DEBUG
//       debugln("Sorted list");
//       for (int i = 0; i < elementCount; i++) {
//         debugln(program_list_sorted[i]);                                  // Print sorted elements
//       }
//     #endif
//   }
//   debugln("file closed / end of sorting function");
//   my_file.close();
// }

int CompareStrings(const void *p1, const void *p2)            // Sorting algorithm 
{
  return strcmp(p1, p2);
}

void delete_program(){
  int index = readString.indexOf("delete=");
  int index_end = readString.indexOf("list=");
  debug("index end = ");
  debugln(index_end);
  String val;
  if (index_end > 0) val = readString.substring(index + 7, index_end - 1);  // Delete from SAVED PROGRAMS page
  else val = readString.substring(index + 7);                               // Delete from main page
  debug("val = ");
  debugln(val);
  char file_name[7] = "00.txt";                                         // Convert readString to file_name
  if (val.length() == 2){
    file_name[0] = val[0];
    file_name[1] = val[1];
  }
  else{
    file_name[0] = '0';
    file_name[1] = val[0];
  }

  SD.remove(file_name);                                                 // Delete file

  char temp[] = {file_name[0], file_name[1]};
  String str = String(temp);
  int program = str.toInt();

  if (program = program_number){                                        // Check if the running file was deleted
    program_run = false;                                                // Running program was deleted so stop running 
    output_reset();
    SD_read(0);                                                         // Load default program 0
  }

  debug("file ");
  debug(file_name);
  debugln(" deleted");
}

void load_program(EthernetClient client){
  debugln("load program function");
  int index = readString.indexOf("program_load=");
  String val = readString.substring(index + 13);
  debugln(val);
  int length = val.length();
  debugln(length);
  char file_name[7] = "00.txt";                                         // Convert readString to file_name
  debug("file name: ");
  if (length < 2) file_name[1] = val[0];
  else{
    file_name[0] = val[0];
    file_name[1] = val[1];
  }
  debugln(file_name);
  my_file = SD.open(file_name);                                         // Try to open program file
  if (my_file) {                                                        // Program exists if true
    readString = "";                                                    // Reset readstring
    int count = 0;
    debugln("in while loop...");
    Serial.print("pre load file ");
    while (my_file.available()){
      char val = my_file.read();
      if (val == '\n') count++;
      readString += val;                                                // Save program data to readstring
    }
    Serial.print("post load file ");
    count++;                                                            // Last line of txt does not have \n
    my_file.close();
    debugln("load program via html");
    update_html(client, 2, count);                                      // If program is saved on SD, load program
  }
  else debugln("failed to open txt file");
}

bool lcd_overwrite_program(String program){
  static int menu_button_pressed;                                       // Variable to store the result of enum
  bool selection = false;                                               // true once user makes selection, ie presses the right button
  bool overwrite = false;                                               // true = overwrite

  lcd.clear();
  lcd.print(F("Program "));
  lcd.print(program);
  lcd.print(F(" exists"));
  lcd.setCursor(0,1);
  lcd.print(F("Overwrite file?"));
  lcd.setCursor(0,2);
  lcd.print(F("YES"));
  lcd.setCursor(0,3);
  lcd.print(F("NO"));
  lcd.setCursor(19,3);
  lcd.print(F("*"));
  
  while (!selection){
    if (menu_flag){                                                     // A button was pressed
      menu_button_pressed = menu_read_button_pressed();                 // check which button was pressed
      switch (menu_button_pressed){
      case up:                                                          // YES selection
        lcd.setCursor(19,2);
        lcd.print(F("*"));
        lcd.setCursor(19,3);
        lcd.print(F(" "));
        overwrite = true;
        break;
      case down:                                                        // NO selection
        lcd.setCursor(19,2);
        lcd.print(F(" "));
        lcd.setCursor(19,3);
        lcd.print(F("*"));
        overwrite = false;
        break;
      case right:                                                       // Make selection
        selection = true;
        break;
      }
      menu_flag = false;
    }
  }

  lcd_update_running();                                                 // Reset UI

  if (overwrite) return true;
  else return false;
}

float map_float(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// void ram_usage(){
//   debug(F("Free memory = "));
//   debugln(freeMemory());
// }

