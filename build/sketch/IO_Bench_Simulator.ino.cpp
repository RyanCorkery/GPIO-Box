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

// Debug
#define DEBUG 1

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#elif DEBUG == 0
#define debug(x)
#define debugln(x)
#endif

// Arduino pinout
const int s1_out = 2;                                         // Speed signal 1 out of Arduino
const int s2_out = 3;
// ethernet pin 4
const int s3_out = 5;
const int s4_out = 6;
const int s5_out = 7;
const int s6_out = 8;
const int s7_out = 9;
// ethernet pin 10
const int s8_out = 11;
const int a1_out = 12;                                        // Analog signal 1 out of Arduino
const int a2_out = 13;
const int menu_interrupt = 18;                                // Interrupt is triggered when any menu button is pressed
// pin 20 - LCD SDA
// pin 21 - LCD SCL
const int menu_down = 22;
const int b1 = 23;                                           // Brake signal 1 out of Arduino
const int menu_up = 24;
const int b2 = 25;
const int menu_left = 26;
const int b3 = 27;
const int menu_right = 28;
const int b4 = 29;
const int menu_run = 30;
const int manual_swtiches_enable = 31;                      // Controls power to manual switches via MOSFET
const int adam6017_power = 32;                             // Power kill switch to ADAM modules
const int b5 = 33;
const int adam6050_power = 34;
const int b6 = 35;
const int latency_led = 36;
const int b7 = 37;
const int b8 = 39;
// ethernet pin 50
// ethernet pin 51
// ethernet pin 52
const int a1_in = A4;
const int a2_in = A5;
const int s1_in = A8;                                     // Speed signal 1 in
const int s2_in = A9;
const int s3_in = A10;
const int s4_in = A11;
const int s5_in = A12;
const int s6_in = A13;
const int s7_in = A14;
const int s8_in = A15;


int input_pins[] = { menu_left, menu_up, menu_down, menu_right, menu_run };           // Inputs are menu buttons and start/stop program button

int output_pins[] = {b1, b2, b3, b4, b5, b6, b7, b8, s1_out, s2_out, s3_out, s4_out, s5_out, s6_out, s7_out, s8_out, a1_out, a2_out};       // Outputs are brake and speed signals and analog
int pots[] = {s1_in, s2_in, s3_in, s4_in, s5_in, s6_in, s7_in, s8_in, a1_in, a2_in};                                                        // Speed signal measurement potentiometers

// Variables 
int mode = 0;                                                                         // Program mode = 0, manual mode = 1, latency test manual = 2, latency test automatic = 3
volatile bool menu_flag = false;                                                      // true when any button is pressed
bool program_run = false;                                                             // Stop program as default
int program_number = 0;                                                               // Current program number
unsigned long program_speed = 1000;                                                   // 1000 placeholder. Program will have this value
bool program_loop = false;


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

// Array of step data
char* data[] = { data_step_0, data_step_1, data_step_2, data_step_3, data_step_4, data_step_5, data_step_6, data_step_7, data_step_8, data_step_9,
        data_step_10, data_step_11, data_step_12, data_step_13, data_step_14, data_step_15, data_step_16, data_step_17, data_step_18, data_step_19 };
//int data_steps = sizeof(data) / sizeof(data[0]);                      // Calculate this in SD function
int data_steps;
// declare data array as char* data[100], 100 may be overkill, desktop app will determine max number of steps in program

typedef enum menu_button_pressed {left, up, down, right} menu_button_pressed;       // Menu button options

LiquidCrystal_I2C lcd(0x3F, 20, 4);                                                 // LCD address = 0x3F. 20x4 LCD

File my_file;

#line 119 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void setup();
#line 181 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void loop();
#line 190 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_running();
#line 230 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_layer_1_selection(int index);
#line 259 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_mode_selection(int index);
#line 286 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_program_number(int program_num);
#line 293 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_program_speed(int program_spd, bool refresh);
#line 305 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void lcd_update_loop_mode();
#line 318 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void menu();
#line 616 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
int menu_read_button_pressed();
#line 635 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void switch_mode();
#line 653 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void manual_mode();
#line 669 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void program_mode();
#line 708 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_manual();
#line 713 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void latency_automatic();
#line 717 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void output_reset();
#line 727 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void SD_write();
#line 782 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void SD_read(int program_num);
#line 862 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void menu_pressed();
#line 119 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
void setup() {
  Serial.begin(9600);
  delay(500);                                                                       // Wait for serial to begin. while(!Serial) not working...

  lcd.init();                                                                       // Initialize LCD display
  lcd.backlight();                                                                  // Print start up display
  /*lcd.setCursor(0, 0);
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
  delay(2000);
  lcd.clear();  */                                                                // END LCD START UP DISPLAY

  digitalWrite(adam6017_power, HIGH);                                             // Power on Adam moudules
  digitalWrite(adam6050_power, HIGH);

  digitalWrite(manual_swtiches_enable, LOW);                                      // Disable manual brake switches 

  digitalWrite(latency_led, LOW);                                                 // Ensure latency LED is off at start up

  if (!SD.begin(4)) {                                                             // Initialize SD card
    lcd.print("SD Initialization");
    lcd.setCursor(0, 1);
    lcd.print("Failed. Try Reboot");
    debugln("SD failed");
    while (1);
  }

  // SD_write();         // ***** TESTING ***** //
  SD_read(0);

  lcd_update_running();                                                           // Update LCD

  for (int i = 0; i < sizeof(output_pins)/sizeof(output_pins[0]); i++) {          // Set all digital outputs
    pinMode(output_pins[i], OUTPUT);
  }
  for (int n = 0; n < sizeof(input_pins)/sizeof(input_pins[0]); n++) {            // Set all digital inputs
    pinMode(input_pins[n], INPUT);
  }
  pinMode(manual_swtiches_enable, OUTPUT);

  output_reset();                                                                 // Ensure outputs are disabled

  attachInterrupt(digitalPinToInterrupt(menu_interrupt), menu_pressed, RISING);   // Menu buttons external interrupt
}

void loop() {
  if (menu_flag) menu();                                                          // Execute menu funciton when external interrupt flag is true

  if (mode == 0) program_mode();                                                  // Execute active mode  
  else if (mode == 1) manual_mode();
  else if (mode == 2) latency_manual();
  else if (mode == 3) latency_automatic();
}

void lcd_update_running() {                                                       // LCD menu for normal running operation
  switch (mode) {
  case 0:
    lcd.clear();
    lcd.print("Mode:        PROGRAM");
    lcd.setCursor(0, 1);
    lcd.print("Program #:        ");
    if (program_number < 10) lcd.print(" ");
    lcd.print(program_number);
    lcd.setCursor(0, 2);
    lcd.print("Interval:    ");
    if (program_speed < 1000) lcd.print(" ");
    lcd.print(program_speed);
    lcd.print(" ms");
    lcd.setCursor(0, 3);
    lcd.print("Loop Mode:    ");
    if (program_loop){
      lcd.setCursor(17, 3);
      lcd.print("YES");
    }
    else{
      lcd.setCursor(18, 3);
      lcd.print("No");
    }
    break;
  case 1:
    lcd.clear();
    lcd.print("Mode: MANUAL");
    break;
  case 2:
    lcd.clear();
    lcd.print("Mode: LATENCY MANUAL");
    break;
  case 3:
    lcd.clear();
    lcd.print("Mode: LATENCY AUTO");
    break;
  }
}

void lcd_update_layer_1_selection(int index) {                        // LCD first layer menu
  lcd.clear();
  lcd.print("Change Mode");
  if (index == 0) {
    lcd.setCursor(19, 0);
    lcd.print("*");
  }
  if (mode == 0) {
    lcd.setCursor(0, 1);
    lcd.print("Change Program");
    if (index == 1) {
      lcd.setCursor(19, 1);
      lcd.print("*");
    }
    lcd.setCursor(0, 2);
    lcd.print("Edit Program Speed");
    if (index == 2) {
      lcd.setCursor(19, 2);
      lcd.print("*");
    }
    lcd.setCursor(0, 3);
    lcd.print("Loop Mode");
    if (index == 3) {
      lcd.setCursor(19, 3);
      lcd.print("*");
    }
  }
}

void lcd_update_mode_selection(int index) {                         // LCD mode selection menu
  lcd.clear();
  lcd.print("PROGRAM");
  if (index == 0) {
    lcd.setCursor(19, 0);
    lcd.print("*");
  }
  lcd.setCursor(0, 1);
  lcd.print("MANUAL");
  if (index == 1) {
    lcd.setCursor(19, 1);
    lcd.print("*");
  }
  lcd.setCursor(0, 2);
  lcd.print("LATENCY MANUAL");
  if (index == 2) {
    lcd.setCursor(19, 2);
    lcd.print("*");
  }
  lcd.setCursor(0, 3);
  lcd.print("LATENCT AUTO");
  if (index == 3) {
    lcd.setCursor(19, 3);
    lcd.print("*");
  }
}

void lcd_update_program_number(int program_num) {
  lcd.clear();
  lcd.print("Choose Program");
  lcd.setCursor(0, 1);
  lcd.print(program_num);
}

void lcd_update_program_speed(int program_spd, bool refresh) {
  if (refresh) {
    lcd.clear();
    lcd.print("Edit Program Speed");
  }
  lcd.setCursor(0, 1);
  lcd.print(program_spd);
  if (program_spd < 1000) lcd.print(" ");
  else if (program_spd < 100) lcd.print("  ");
  else if (program_spd < 10) lcd.print("   ");
}

void lcd_update_loop_mode(){
  lcd.clear();
  lcd.print("Loop Mode:");
  if (program_loop){
  lcd.setCursor(17, 0);
  lcd.print("YES");
  }
  else{
  lcd.setCursor(18, 0);
  lcd.print("NO");
  }
}

void menu() {                                       // UI button pressed, execute menu
  // Menu Layers
  // 0 - wake UI
  // 1 - Choose mode, choose program, change program speed
  // 2 - settings for elements in layer 1
  // Start/stop program

  static int index_layer = 0;                                           // Menu layer: Enter menu [0], Mode, Program Number, Program Speed [1], Setting [2], Select/Enter (reset UI) [3]
  static int index_layer_1_option = 0;                                  // Index within menu layer 1
  static int index_layer_2_option = 0;                                  // Index within menu layer 2
  static int menu_button_pressed;                                       // Variable to store the result of enum
  static int mode_selection = 0;                                        // Program mode = 0, manual mode = 1, latency test manual = 2, latency test automatic = 3
  static int program_number_selection = program_number;                 // Selection is the menu memory version of actual variable
  static int program_speed_selection = program_speed;
  static unsigned long btn_pressed = 0;                                 // Track how long the button is held down to change speed. Click change by one, hold change quickly
  static unsigned long btn_hold_threshold = 100;                        // Time needed to activate button held down for quick variable change
  bool btn_hold_flag = false;                                           // Check if btn was held down or clicked
  int btn_hold_count = 0;                                               // Count how many cycles the btn has been held down for

  if (digitalRead(menu_run)) {                                         // Program Start/Stop button pressed
  switch(mode){
    case 0:
    Serial.println("Start / Stop Program");
    program_run = !program_run;                                         // Toggle start stop program
    if (!program_run) output_reset();                                   // Start stop button only affects Progam Mode
    break;
  }
    
  }

  else {                                                                // Menu button pressed
    switch (index_layer) {
    case 0:                                                             // Layer 0 = Enter menu
      index_layer++;                                                    // Step into next menu layer
      Serial.println("Change Mode");                                    // Wake UI
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
        Serial.print("Back to running UI, Mode: ");                     // Reset UI to running information  
        Serial.println(mode);
        lcd_update_running();                                           // Update LCD running display
        break;
      case up:
        if (index_layer_1_option > 0 && mode ==0) index_layer_1_option--;             // Decrement through options. Only increment option when in program mode. No need to change these settings unless we are in program mode

        if (index_layer_1_option == 0) Serial.println("CHANGE MODE");
        else if (index_layer_1_option == 1) Serial.println("CHANGE PROGRAM");
        else if (index_layer_1_option == 2) Serial.println("CHANGE PROGRAM SPEED");
        lcd_update_layer_1_selection(index_layer_1_option);                           // Layer 1 LCD menu
        break;
      case down:
        if (index_layer_1_option < 3 && mode == 0) index_layer_1_option++;            // Increment through options. Only increment option when in program mode. No need to change these settings unless we are in program mode

        if (index_layer_1_option == 0) Serial.println("CHANGE MODE");
        else if (index_layer_1_option == 1) Serial.println("CHANGE PROGRAM");
        else if (index_layer_1_option == 2) Serial.println("CHANGE PROGRAM SPEED");
        lcd_update_layer_1_selection(index_layer_1_option);                           // Layer 1 LCD menu
        break;
      case right:
        index_layer++;                                                  // Select/Enter. Step into next layer of menu
        switch (index_layer_1_option) {
          case 0:
            if (mode == 0) {
              Serial.println("Program Mode");                           // Display current mode
              index_layer_2_option = 0;
            }
            else if (mode == 1) {
              Serial.println("Manual Mode");                           // Display current mode
              index_layer_2_option = 1;
            }
            else if (mode == 2) {
              Serial.println("Latency Mode Manual");                  // Display current mode
              index_layer_2_option = 2;
            }
            else if (mode == 3) {
              Serial.println("Latency Mode Automatic");               // Display current mode
              index_layer_2_option = 3;
            }
            lcd_update_mode_selection(index_layer_2_option);          // Update LCD menu
            break;
          case 1:
            Serial.println(program_number);                           // Display current program number
            lcd_update_program_number(program_number_selection);
            break;
          case 2:
            Serial.println(program_speed);                            // Display current program speed
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
        if (index_layer_1_option == 0) Serial.println("CHANGE MODE");
        if (mode == 0) {
          if (index_layer_1_option == 1) Serial.println("CHANGE PROGRAM");
          else Serial.println("CHANGE PROGRAM SPEED");
        }
        lcd_update_layer_1_selection(index_layer_1_option);         // Layer 1 LCD menu
        break;
      case up:
        switch (index_layer_1_option) {                             // Choose mode option = 0, change program = 1, change program speed = 2
        case 0:                                                     // MODE selection
          if (index_layer_2_option > 0) index_layer_2_option--;     // Decrement through options

          switch (index_layer_2_option) {
          case 0:
            Serial.println("Program Mode");                     
            index_layer_2_option = 0;                               // Mode to select = program
            break;
          case 1:
            Serial.println("Manual Mode");
            index_layer_2_option = 1;                               // Mode to select = manual
            break;
          case 2:
            Serial.println("Latency Mode Manual");
            index_layer_2_option = 2;                               // Mode to select = latency mode manual
            break;
          case 3:
            Serial.println("Latency Mode Automatic");
            index_layer_2_option = 3;                               // Mode to select = latency mode automatic                        
            break;
          }
          Serial.println(index_layer_2_option);
          lcd_update_mode_selection(index_layer_2_option);          // Update LCD menu
          break;
        case 1:                                                     // PROGRAM NUMBER selection
          if (program_number_selection < 99) program_number_selection++;        // Increase program number
          Serial.println(program_number_selection);
          lcd_update_program_number(program_number_selection);
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
          }
          else btn_hold_flag = false;                              // Reset flag
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
            Serial.println("Program Mode");
            mode_selection = 0;                                  // Mode to select = program
            break;
          case 1:
            Serial.println("Manual Mode");
            mode_selection = 1;                                 // Mode to select = manual
            break;
          case 2:
            Serial.println("Latency Mode Manual");
            mode_selection = 2;                                 // Mode to select = latency mode manual
            break;
          case 3:
            Serial.println("Latency Mode Automatic");
            mode_selection = 3;                                 // Mode to select = latency mode automatic
            break;
          }
          lcd_update_mode_selection(index_layer_2_option);      // Update LCD menu
          break;
        case 1:                                                 // PROGRAM NUMBER selection
          if (program_number_selection > 0) program_number_selection--;       // Decrease program number
          Serial.println(program_number_selection);
          lcd_update_program_number(program_number_selection);
          break;
        case 2:                                                 // PROGRAM SPEED selection
          btn_pressed = millis();
          while (digitalRead(menu_down)) {
            if (btn_hold_count <= 20) {
              if (millis() - btn_pressed >= 100) {                  // Decrease program speed quickly by holding down btn. Low speed
                if (program_speed_selection > 0) program_speed_selection--;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else if (btn_hold_count <= 500) {
              if (millis() - btn_pressed >= 10) {                   // Decrease program speed quickly by holding down btn. Medium speed
                if (program_speed_selection > 0) program_speed_selection--;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else {
              if (millis() - btn_pressed >= 1) {                    // Decrease program speed quickly by holding down btn. High speed
                if (program_speed_selection > 0) program_speed_selection -= 10;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
          }
          if (!btn_hold_flag) {                                     // Decrease program speed once by click
            if (program_speed_selection > 0) program_speed_selection--;
            lcd_update_program_speed(program_speed_selection, false);
          }
          else btn_hold_flag = false;                               // Reset flag
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
          Serial.print("Back to running UI, mode: ");
          Serial.println(mode);
          lcd_update_running();                                     // Update LCD running display
          switch_mode();
          break;
        case 1:
          program_number = program_number_selection;
          Serial.print("Program number: ");
          Serial.println(program_number);
          lcd_update_running();                                     // Update LCD running display
          break;
        case 2:
          program_speed = program_speed_selection;
          Serial.print("Program speed: ");
          Serial.println(program_speed);
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
  if (digitalRead(menu_left)) {
    delay(300);                                                     // Needs a bit of debounce.... (check schmitt trigger)
    return left;                                                    // Left
  }
  else if (digitalRead(menu_up)) {
    delay(300);                                                     // Needs a bit of debounce.... (check schmitt trigger)
    return up;                                                      // Up
  }
  else if (digitalRead(menu_down)) {
    delay(300);                                                     // Needs a bit of debounce.... (check schmitt trigger)
    return down;                                                    // Down
  }
  else if (digitalRead(menu_right)) {
    delay(300);                                                     // Needs a bit of debounce.... (check schmitt trigger)
    return right;                                                   // Right
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
      val = map(val, 0, 1023, 35, 255);
      if (val <= 41) val = 0;                                       // 4-20ma -> 1-5V -> 50-255 analog write
      else if (val >= 242) val = 242;  
      analogWrite(output_pins[i + 8], val);                         // Output speed/analog signals
      if (i == 8) debugln(val);
    }
  }
}

void program_mode() {                                               // Loop through the number of steps in the program and output brake/speed/analog signals per step in the loop
  static unsigned long program_time = 0;                            // Current time 
  static int step = 0;                                              // Current step in program
  
  if (program_run) {                                                // Check if START/STOP button is pressed (Run program)
    if (millis() - program_time >= program_speed) {                 // Check if update time has been reached. Time interval can be changed by user via menu, this is an option
      int val_int;
      char val_char[3] = {'0', '0', '0'};
      
      for (int n = 0; n < 8; n++) {                                 // Brake signal digital outputs. Number of brake signals. 
        val_char[2] = data[step][n];                                // Read brake signal from program data
        val_int = atoi(val_char);
        debug(val_int);
        debug(" ");
        digitalWrite(output_pins[n], val_int);
      }
      debugln("");
      for (int m = 0; m < 10; m++) {                                // Speed signal & analog outputs. Number of signals = 10
        for (int p = 0; p < 3; p++) {
          val_char[p] = data[step][p + 3 * m + 8];                  // Read speed signal from program data
        }
        val_int = atoi(val_char);
        analogWrite(output_pins[m + 8], val_int); 
      }

      step++;
      if (step == data_steps) {
        step = 0;           
        if (!program_loop) {
          program_run = false;
          delay(program_speed);
          output_reset();
        }
      }
      program_time = millis();
    }
  }
}

void latency_manual() {
  if (digitalRead(menu_run) == HIGH) digitalWrite(latency_led, HIGH);
  else digitalWrite(latency_led, LOW);
}

void latency_automatic() {

}

void output_reset() {                                           // Turn off all MOSFET swtiches from program mode, and set speed signals to zero
  for (int i = 0; i < 8; i++) {                                 // 8 brake signals
    digitalWrite(output_pins[i], LOW);                          // Turn of brake signals
  }
  for (int n = 0; n < 10; n++) {                                // 8 speed signals, 2 analog signals
    analogWrite(output_pins[n + 8], 0);                         // Turn off speed signals
  }
  digitalWrite(manual_swtiches_enable, LOW);                    // Disable manual switches
}

void SD_write() {                                               // Write data to SD card
  // Check if program exists
  // Reset char* data[] elements to '\0'? Need to reset each element
  // Open .txt file 
  // read data and save each line as element in char* data[]
  // calculate nubmber of steps in program -> data_steps
  // Determine program speed -> program_speed
  SD.remove("00.txt");                                    // Remove file. Maybe just overwrite contents?

  my_file = SD.open("00.txt", FILE_WRITE);                      // Create program 0

  if (my_file) {
    my_file.print(0);                                           // Program #
    my_file.print(0);

    my_file.print('\n');

    my_file.print("500");                                      // Program speed. Step time [ms]

    my_file.print('\n');

    my_file.print("10000000255000000000000000000000000000");                          // Program data. 4 steps
    my_file.print('\n');
    my_file.print("01000000000255000000000000000000000000");
    my_file.print('\n');
    my_file.print("00100000000000255000000000000000000000");
    my_file.print('\n');
    my_file.print("00010000000000000255000000000000000000");
    my_file.print('\n');
    my_file.print("00001000000000000000255000000000000000");                        
    my_file.print('\n');
    my_file.print("00000100000000000000000255000000000000");
    my_file.print('\n');
    my_file.print("00000010000000000000000000255000000000");
    my_file.print('\n');
    my_file.print("00000001000000000000000000000255000000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000000255");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000100000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000150000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000200000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000250000");
    my_file.print('\n');

    my_file.close();
  }
  else {
    debugln("file didn't open");
  } 
}

void SD_read(int program_num) {                               // Read and process data. program_number = selcted program (1, 2, 3....)
  // Check if program exists
  // Reset char* data[] elements to '\0'? Need to reset each element
  // Open .txt file 
  // read data and save each line as element in char* data[]
  // calculate nubmber of steps in program -> data_steps
  // Determine program speed -> program_speed

  char file_name[7] = { "00.txt" };                           // Defualt file name
  String str;
  str = String(program_num);                                  // Convert program number to string
  if (program_num < 10) file_name[1] = str[0];                // Update file name 
  else {
    file_name[0] = str[0];
    file_name[1] = str[1];
  }

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
      }
      else {
        debug(SD_step);
        debug("  ");

        if (SD_step == 0) {
          program_number = atoi(program_num_char);                // Convert data to int
          debugln(program_number);
        }
        else if (SD_step == 1) {
          program_speed = atoi(program_spd_char);                 // Convert data to int
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
    lcd.print("Program Not Found");
    delay(5000);
  }
  lcd_update_running();                                 // Update LCD
}

void menu_pressed() {                                   // External interrupt triggered when any menu or start/stop button is pressed
  menu_flag = true;
}

