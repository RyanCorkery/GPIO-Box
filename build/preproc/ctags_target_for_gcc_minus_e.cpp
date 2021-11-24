# 1 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
//  Name:    GPIO_REV_2.ino
//  Created: 7/7/2021 11:54:20 AM
//  Author:  Ryan Corkery

// #include <avr/iom2560.h>
# 7 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 2
# 8 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 2
# 9 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 2
# 10 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 2
# 11 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 2
// #include <MemoryFree.h>

// Debug
# 24 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
// Arduino pinout
const int s1_out 
# 25 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 25 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 2; // Speed signal 1 out of Arduino
const int s2_out 
# 26 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 26 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 3;
// ethernet pin 4
const int s3_out 
# 28 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 28 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 5;
const int s4_out 
# 29 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 29 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 6;
const int s5_out 
# 30 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 30 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 7;
const int s6_out 
# 31 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 31 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 8;
const int s7_out 
# 32 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 32 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 9;
// ethernet pin 10
const int s8_out 
# 34 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 34 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 11;
const int a1_out 
# 35 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 35 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 12; // Analog signal 1 out of Arduino
const int a2_out 
# 36 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                __attribute__((__progmem__)) 
# 36 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                        = 13;
const int menu_interrupt 
# 37 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                        __attribute__((__progmem__)) 
# 37 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                = 18; // Interrupt is triggered when any menu button is pressed
// pin 20 - LCD SDA
// pin 21 - LCD SCL
const int menu_down 
# 40 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                   __attribute__((__progmem__)) 
# 40 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                           = 22;
const int b1 
# 41 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 41 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 23; // Brake signal 1 out of Arduino
const int menu_up 
# 42 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 __attribute__((__progmem__)) 
# 42 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                         = 24;
const int b2 
# 43 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 43 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 25;
const int menu_left 
# 44 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                   __attribute__((__progmem__)) 
# 44 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                           = 26;
const int b3 
# 45 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 45 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 27;
const int menu_right 
# 46 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    __attribute__((__progmem__)) 
# 46 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                            = 28;
const int b4 
# 47 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 47 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 29;
const int menu_run 
# 48 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                  __attribute__((__progmem__)) 
# 48 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                          = 30;
const int manual_swtiches_enable 
# 49 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                __attribute__((__progmem__)) 
# 49 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                        = 31; // Controls power to manual switches via MOSFET
const int adam6017_power 
# 50 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                        __attribute__((__progmem__)) 
# 50 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                = 32; // Power kill switch to ADAM modules
const int b5 
# 51 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 51 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 33;
const int adam6050_power 
# 52 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                        __attribute__((__progmem__)) 
# 52 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                = 34;
const int b6 
# 53 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 53 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 35;
const int latency_led 
# 54 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                     __attribute__((__progmem__)) 
# 54 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                             = 36;
const int b7 
# 55 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 55 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 37;
const int adam_do_0 
# 56 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                   __attribute__((__progmem__)) 
# 56 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                           = 38; // Input to read when ADAM DO triggers relay 
const int b8 
# 57 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
            __attribute__((__progmem__)) 
# 57 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    = 39;
// ethernet pin 50
// ethernet pin 51
// ethernet pin 52
const int a1_in 
# 61 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 61 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A4;
const int a2_in 
# 62 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 62 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A5;
const int s1_in 
# 63 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 63 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A8; // Speed signal 1 in
const int s2_in 
# 64 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 64 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A9;
const int s3_in 
# 65 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 65 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A10;
const int s4_in 
# 66 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 66 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A11;
const int s5_in 
# 67 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 67 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A12;
const int s6_in 
# 68 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 68 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A13;
const int s7_in 
# 69 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 69 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A14;
const int s8_in 
# 70 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               __attribute__((__progmem__)) 
# 70 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                       = A15;

const int input_pins[] 
# 72 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 72 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = { menu_left, menu_up, menu_down, menu_right, menu_run, adam_do_0 }; // Inputs are menu buttons and start/stop program button, ADAM module digital outputs

const int output_pins[] = {b1, b2, b3, b4, b5, b6, b7, b8, s1_out, s2_out, s3_out, s4_out, s5_out, s6_out, s7_out, s8_out, a1_out, a2_out}; // Outputs are brake and speed signals and analog
const int pots[] = {s1_in, s2_in, s3_in, s4_in, s5_in, s6_in, s7_in, s8_in, a1_in, a2_in}; // Speed signal measurement potentiometers

// Variables 
int mode = 0; // Program mode = 0, manual mode = 1, latency test manual = 2, latency test automatic = 3
volatile bool menu_flag = false; // true when any button is pressed
bool program_run = false; // Stop program as default
int program_number = 0; // Current program number
unsigned long program_speed = 1000; // 1000 placeholder. Program will have this value
bool program_loop = false;
bool latency_run = false; // Run latency test

// SD card program data variables
char data_step_0[38]; // Initailize variables
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

char description[100] = {"Hello World"}; // 100 char limit *** can maybe be increased, need to test

// Array of step data
char* data[] = { data_step_0, data_step_1, data_step_2, data_step_3, data_step_4, data_step_5, data_step_6, data_step_7, data_step_8, data_step_9,
        data_step_10, data_step_11, data_step_12, data_step_13, data_step_14, data_step_15, data_step_16, data_step_17, data_step_18, data_step_19 };
//int data_steps = sizeof(data) / sizeof(data[0]);                      // Calculate this in SD function
int data_steps;
// declare data array as char* data[100], 100 may be overkill, desktop app will determine max number of steps in program

// char program_list[300] = {"00-01-"};                                                // Array to store file names
char program_list_sorted[100][7]; // Array to store sorted file names
String program_list_string = "";

typedef enum menu_button_pressed {left, up, down, right} menu_button_pressed; // Menu button options

LiquidCrystal_I2C lcd(0x3F, 20, 4); // LCD address = 0x3F. 20x4 LCD

File my_file;

String readString; // Ethernet variables
byte mac[] = {0xA8, 0x61, 0x0A, 0xAE, 0x83, 0xB1}; // Must be unique for each GPIO box Arduino
IPAddress ip(192, 168, 0, 116); // Must be unique for each GPIO box Arduino
EthernetServer server(80); // (port 80 is default for HTTP):

EthernetClient client_null; // Update html without client

void setup() {
  Serial.begin(9600);
  delay(500); // Wait for serial to begin. while(!Serial) not working...

  digitalWrite(adam6017_power, 0x1); // Power on Adam moudules
  digitalWrite(adam6050_power, 0x1);

  digitalWrite(manual_swtiches_enable, 0x0); // Disable manual brake switches 

  digitalWrite(latency_led, 0x0); // Ensure latency LED is off at start up

  Ethernet.begin(mac, ip); // start the Ethernet connection and the server:
  if (Ethernet.hardwareStatus() == EthernetNoHardware) { // Check for Ethernet hardware present
    ;
    while (1){}
  }
  server.begin(); // start Arduino server
  ;
  ;

  lcd.init(); // Initialize LCD display
  lcd.backlight(); // Print start up display

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
    lcd.clear(); // END LCD START UP DISPLAY


  if (!SD.begin(4)) { // Initialize SD card
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 181 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 181 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "SD Initialization"
# 181 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 181 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    lcd.setCursor(0, 1);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 183 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 183 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Failed. Try Reboot"
# 183 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 183 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    ;
    while (1);
  }

  SD_read(0); // Load default program 

  for (int i = 0; i < sizeof(output_pins)/sizeof(output_pins[0]); i++) { // Set all digital outputs
    pinMode(output_pins[i], 0x1);
  }
  for (int n = 0; n < sizeof(input_pins)/sizeof(input_pins[0]); n++) { // Set all digital inputs
    pinMode(input_pins[n], 0x0);
  }
  pinMode(manual_swtiches_enable, 0x1);

  output_reset(); // Ensure outputs are disabled

  list_files(client_null, false);
  ;

  // readString.reserve(1000);

  attachInterrupt(((menu_interrupt) == 2 ? 0 : ((menu_interrupt) == 3 ? 1 : ((menu_interrupt) >= 18 && (menu_interrupt) <= 21 ? 23 - (menu_interrupt) : -1))), menu_pressed, 3); // Menu buttons external interrupt

  delay(2000); // Leave start up message for 2 seconds
  lcd_update_running(); // Update LCD
} // END SETUP()

void loop() {
  if (menu_flag) menu(); // Execute menu funciton when external interrupt flag is true

  if (mode == 0) program_mode(); // Execute active mode  
  else if (mode == 1) manual_mode();
  else if (mode == 2) latency_manual();
  else if (mode == 3) latency_automatic();

  ethernet();
}

void lcd_update_running() { // LCD menu for normal running operation
  switch (mode) {
  case 0:
    lcd.clear();
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 226 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 226 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Mode:        PROGRAM"
# 226 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 226 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    lcd.setCursor(0, 1);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 228 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 228 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Program #:        "
# 228 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 228 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    if (program_number < 10) lcd.print(" ");
    lcd.print(program_number);
    lcd.setCursor(0, 2);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 232 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 232 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Interval:    "
# 232 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 232 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    if (program_speed < 1000) lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 233 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                       (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 233 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                       " "
# 233 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                       ); &__c[0];}))
# 233 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                       )));
    lcd.print(program_speed);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 235 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 235 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             " ms"
# 235 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 235 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    lcd.setCursor(0, 3);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 237 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 237 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Loop Mode:    "
# 237 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 237 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    if (program_loop){
      lcd.setCursor(17, 3);
      lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 240 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 240 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               "YES"
# 240 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               ); &__c[0];}))
# 240 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               )));
    }
    else{
      lcd.setCursor(18, 3);
      lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 244 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 244 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               "No"
# 244 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               ); &__c[0];}))
# 244 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               )));
    }
    break;
  case 1:
    lcd.clear();
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 249 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 249 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Mode: MANUAL"
# 249 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 249 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    break;
  case 2:
    lcd.clear();
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 253 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 253 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Mode: LATENCY MANUAL"
# 253 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 253 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    lcd.setCursor(0,1);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 255 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 255 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "ADAM 6050 DO 0"
# 255 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 255 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    latency_running_state(); // Update LCD display 
    break;
  case 3:
    lcd.clear();
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 260 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 260 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Mode: LATENCY AUTO"
# 260 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 260 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    lcd.setCursor(0,1);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 262 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 262 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "ADAM 6050 DO 0"
# 262 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 262 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    latency_running_state(); // Update LCD display 
    break;
  }
}

void lcd_update_layer_1_selection(int index) { // LCD first layer menu
  lcd.clear();
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 270 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 270 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "Change Mode"
# 270 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 270 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  if (index == 0) {
    lcd.setCursor(19, 0);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 273 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 273 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "*"
# 273 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 273 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
  if (mode == 0) {
    lcd.setCursor(0, 1);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 277 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 277 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Change Program"
# 277 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 277 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    if (index == 1) {
      lcd.setCursor(19, 1);
      lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 280 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 280 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               "*"
# 280 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               ); &__c[0];}))
# 280 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               )));
    }
    lcd.setCursor(0, 2);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 283 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 283 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Edit Program Speed"
# 283 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 283 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    if (index == 2) {
      lcd.setCursor(19, 2);
      lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 286 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 286 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               "*"
# 286 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               ); &__c[0];}))
# 286 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               )));
    }
    lcd.setCursor(0, 3);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 289 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 289 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Loop Mode"
# 289 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 289 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    if (index == 3) {
      lcd.setCursor(19, 3);
      lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 292 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 292 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               "*"
# 292 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
               ); &__c[0];}))
# 292 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
               )));
    }
  }
}

void lcd_update_mode_selection(int index) { // LCD mode selection menu
  lcd.clear();
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 299 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 299 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "PROGRAM"
# 299 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 299 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  if (index == 0) {
    lcd.setCursor(19, 0);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 302 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 302 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "*"
# 302 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 302 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
  lcd.setCursor(0, 1);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 305 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 305 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "MANUAL"
# 305 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 305 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  if (index == 1) {
    lcd.setCursor(19, 1);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 308 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 308 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "*"
# 308 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 308 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
  lcd.setCursor(0, 2);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 311 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 311 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "LATENCY MANUAL"
# 311 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 311 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  if (index == 2) {
    lcd.setCursor(19, 2);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 314 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 314 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "*"
# 314 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 314 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
  lcd.setCursor(0, 3);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 317 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 317 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "LATENCY AUTO"
# 317 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 317 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  if (index == 3) {
    lcd.setCursor(19, 3);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 320 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 320 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "*"
# 320 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 320 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
}

void lcd_update_program_number(int program_num) {
  lcd.clear();
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 326 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 326 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "Choose Program"
# 326 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 326 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
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
    else if (val != '+') last_line += val; // Replace + signs with space
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
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 363 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 363 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "..."
# 363 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 363 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }

  my_file.close();
}

void lcd_update_program_speed(int program_spd, bool refresh) {
  if (refresh) {
    lcd.clear();
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 372 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 372 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Edit Program Speed"
# 372 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 372 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
  lcd.setCursor(0, 1);
  lcd.print(program_spd);
  if (program_spd < 1000) lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 376 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                   (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 376 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                   " "
# 376 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                   ); &__c[0];}))
# 376 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                   )));
  else if (program_spd < 100) lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 377 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                       (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 377 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                       "  "
# 377 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                       ); &__c[0];}))
# 377 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                       )));
  else if (program_spd < 10) lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 378 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                      (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 378 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                      "   "
# 378 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                                      ); &__c[0];}))
# 378 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                      )));
}

void lcd_update_loop_mode(){
  lcd.clear();
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 383 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 383 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "Loop Mode:"
# 383 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 383 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  if (program_loop){
  lcd.setCursor(17, 0);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 386 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 386 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "YES"
# 386 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 386 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  }
  else{
  lcd.setCursor(18, 0);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 390 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 390 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "NO"
# 390 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 390 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  }
}

void menu() { // UI button pressed, execute menu
  // Menu Layers
  // 0 - wake UI
  // 1 - Choose mode, choose program, change program speed
  // 2 - settings for elements in layer 1
  // 3 - Select/enter
  // Start/stop program

  static int index_layer = 0; // Menu layer: Enter menu [0], Mode, Program Number, Program Speed [1], Setting [2], Select/Enter (reset UI) [3]
  static int index_layer_1_option = 0; // Index within menu layer 1
  static int index_layer_2_option = 0; // Index within menu layer 2
  static int menu_button_pressed; // Variable to store the result of enum
  static int mode_selection = 0; // Program mode = 0, manual mode = 1, latency test manual = 2, latency test automatic = 3
  static int program_number_selection = program_number; // Selection is the menu memory version of actual variable
  static int program_speed_selection = program_speed;
  static unsigned long btn_pressed = 0; // Track how long the button is held down to change speed. Click change by one, hold to change quickly
  static unsigned long btn_hold_threshold = 100; // Time needed to activate button held down for quick variable change
  bool btn_hold_flag = false; // Check if btn was held down or clicked
  int btn_hold_count = 0; // Count how many cycles the btn has been held down for

  if (digitalRead(menu_run)) { // Program Start/Stop button pressed
  switch(mode){
    case 0:
      ;
      program_run = !program_run; // Toggle start stop program
      if (!program_run) output_reset();
      // else digitalWrite(latency_led, HIGH);                             // Turn on LED. Changed latency_led to running_led. Would need to add hardware                               
      break;
    case 2:
      latency_run = true; // Start manual latency test
      break;
    case 3:
      latency_run = !latency_run; // Start/stop automatic latency test
      latency_running_state(); // Update LCD display 
      break;
    }
  }
  else { // Menu button pressed
    switch (index_layer) {
    case 0: // Layer 0 = Enter menu
      index_layer++; // Step into next menu layer
      ; // Wake UI
      index_layer_1_option = 0; // Reset layer 1 index option
      index_layer_2_option = 0; // Reset layer 2 index option
      program_number_selection = program_number; // Reset menu
      program_speed_selection = program_speed;
      lcd_update_layer_1_selection(index_layer_1_option); // Layer 1 LCD menu
      break;
    case 1: // Layer 1 = Mode, Program Speed, Program Number
      menu_button_pressed = menu_read_button_pressed();
      switch (menu_button_pressed) {
      case left:
        index_layer--; // Step into previous menu layer (go back)
        ; // Reset UI to running information  
        ;
        lcd_update_running(); // Update LCD running display
        break;
      case up:
        if (index_layer_1_option > 0 && mode ==0) index_layer_1_option--; // Decrement through options. Only increment option when in program mode. No need to change these settings unless we are in program mode

        if (index_layer_1_option == 0) ;
        else if (index_layer_1_option == 1) ;
        else if (index_layer_1_option == 2) ;
        lcd_update_layer_1_selection(index_layer_1_option); // Layer 1 LCD menu
        break;
      case down:
        if (index_layer_1_option < 3 && mode == 0) index_layer_1_option++; // Increment through options. Only increment option when in program mode. No need to change these settings unless we are in program mode

        if (index_layer_1_option == 0) ;
        else if (index_layer_1_option == 1) ;
        else if (index_layer_1_option == 2) ;
        lcd_update_layer_1_selection(index_layer_1_option); // Layer 1 LCD menu
        break;
      case right:
        index_layer++; // Select/Enter. Step into next layer of menu
        switch (index_layer_1_option) {
          case 0:
            if (mode == 0) {
              ; // Display current mode
              index_layer_2_option = 0;
            }
            else if (mode == 1) {
              ; // Display current mode
              index_layer_2_option = 1;
            }
            else if (mode == 2) {
              ; // Display current mode
              index_layer_2_option = 2;
            }
            else if (mode == 3) {
              ; // Display current mode
              index_layer_2_option = 3;
            }
            lcd_update_mode_selection(index_layer_2_option); // Update LCD menu
            break;
          case 1:
            ; // Display current program number
            lcd_update_program_number(program_number_selection);
            break;
          case 2:
            ; // Display current program speed
            lcd_update_program_speed(program_speed_selection, true);
            break;
          case 3:
            lcd_update_loop_mode();
            break;
        }
        break;
      }
      break;
    case 2: // Layer 2 = Setting
      menu_button_pressed = menu_read_button_pressed();
      switch (menu_button_pressed) {
      case left:
        index_layer--; // Step into previous menu layer (go back)
        if (index_layer_1_option == 0) ;
        if (mode == 0) {
          if (index_layer_1_option == 1) ;
          else ;
        }
        lcd_update_layer_1_selection(index_layer_1_option); // Layer 1 LCD menu
        break;
      case up:
        switch (index_layer_1_option) { // Choose mode option = 0, change program = 1, change program speed = 2
        case 0: // MODE selection
          if (index_layer_2_option > 0) index_layer_2_option--; // Decrement through options

          switch (index_layer_2_option) {
          case 0:
            ;
            index_layer_2_option = 0; // Mode to select = program
            break;
          case 1:
            ;
            index_layer_2_option = 1; // Mode to select = manual
            break;
          case 2:
            ;
            index_layer_2_option = 2; // Mode to select = latency mode manual
            break;
          case 3:
            ;
            index_layer_2_option = 3; // Mode to select = latency mode automatic                        
            break;
          }
          ;
          lcd_update_mode_selection(index_layer_2_option); // Update LCD menu
          break;
        case 1: // PROGRAM NUMBER selection
          btn_pressed = millis();
          while (digitalRead(menu_up)) {
              if (millis() - btn_pressed >= 100) { // Increase program number quickly by holding down btn
                // if (program_number_selection < 99) program_number_selection++;
                if (program_number_selection < sizeof(program_list_string)/3) program_number_selection++;
                btn_pressed = millis();
                lcd_update_program_number(program_number_selection);
                btn_hold_flag = true;
              }
          }
          if (!btn_hold_flag) { // Increase program speed once by click
            // if (program_number_selection < 99) program_number_selection++;
            if (program_number_selection < sizeof(program_list_string)/3) program_number_selection++;
            lcd_update_program_number(program_number_selection);
            btn_hold_flag = false; // Reset flag
          }
          break;
        case 2: // PROGRAM SPEED selection
          btn_pressed = millis();
          while (digitalRead(menu_up)) {
            if (btn_hold_count <= 20) {
              if (millis() - btn_pressed >= 100) { // Increase program speed quickly by holding down btn. Low speed
                if (program_speed_selection < 9999) program_speed_selection++;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else if (btn_hold_count <= 500) {
              if (millis() - btn_pressed >= 10) { // Increase program speed quickly by holding down btn. Medium speed
                if (program_speed_selection < 9999) program_speed_selection++;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else {
              if (millis() - btn_pressed >= 1) { // Increase program speed quickly by holding down btn. High speed
                if (program_speed_selection < 9999) program_speed_selection+=10;
                if (program_speed_selection > 9999) program_speed_selection = 9999; // Avoid going over maximum 
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
          }
          if (!btn_hold_flag) { // Increase program speed once by click
            if (program_speed_selection < 9999) program_speed_selection++;
            lcd_update_program_speed(program_speed_selection, false);
            btn_hold_flag = false; // Reset flag
          }
          break;
          case 3:
            if (!program_loop) program_loop = true;
            lcd_update_loop_mode();
            break;
        }
        break;
      case down:
        switch (index_layer_1_option) { // Choose mode option = 0, change program = 1, change program speed = 2
        case 0: // MODE selection
          if (index_layer_2_option < 3) index_layer_2_option++; // Decrement through options

          switch (index_layer_2_option) {
          case 0:
            ;
            mode_selection = 0; // Mode to select = program
            break;
          case 1:
            ;
            mode_selection = 1; // Mode to select = manual
            break;
          case 2:
            ;
            mode_selection = 2; // Mode to select = latency mode manual
            break;
          case 3:
            ;
            mode_selection = 3; // Mode to select = latency mode automatic
            break;
          }
          lcd_update_mode_selection(index_layer_2_option); // Update LCD menu
          break;
        case 1: // PROGRAM NUMBER selection
          btn_pressed = millis();
          while (digitalRead(menu_down)) {
              if (millis() - btn_pressed >= 100) { // Decrease program number quickly by holding down btn
                if (program_number_selection > 0) program_number_selection--;
                btn_pressed = millis();
                lcd_update_program_number(program_number_selection);
                btn_hold_flag = true;
              }
          }
          if (!btn_hold_flag) { // Decrease program speed once by click
            if (program_number_selection > 0) program_number_selection--;
            lcd_update_program_number(program_number_selection);
            btn_hold_flag = false; // Reset flag
          }
          break;
        case 2: // PROGRAM SPEED selection
          btn_pressed = millis();
          while (digitalRead(menu_down)) {
            if (btn_hold_count <= 20) {
              if (millis() - btn_pressed >= 100) { // Decrease program speed quickly by holding down btn. Low speed
                if (program_speed_selection > 1) program_speed_selection--;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else if (btn_hold_count <= 500) {
              if (millis() - btn_pressed >= 10) { // Decrease program speed quickly by holding down btn. Medium speed
                if (program_speed_selection > 1) program_speed_selection--;
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
            else {
              if (millis() - btn_pressed >= 1) { // Decrease program speed quickly by holding down btn. High speed
                if (program_speed_selection > 1) program_speed_selection -= 10;
                if (program_speed_selection < 1) program_speed_selection = 1; // Avoid less than minimum
                btn_pressed = millis();
                lcd_update_program_speed(program_speed_selection, false);
                btn_hold_flag = true;
                btn_hold_count++;
              }
            }
          }
          if (!btn_hold_flag) { // Decrease program speed once by click
            if (program_speed_selection > 1) program_speed_selection--;
            lcd_update_program_speed(program_speed_selection, false);
            btn_hold_flag = false; // Reset flag
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
          mode = index_layer_2_option; // Updated mode to new selection
          ;
          ;
          lcd_update_running(); // Update LCD running display
          switch_mode();
          break;
        case 1:
          program_number = program_number_selection;
          ;
          ;
          SD_read(program_number); // Load new program
          program_run = false; // Stop running when program changes
          output_reset();
          lcd_update_running(); // Update LCD running display
          break;
        case 2:
          program_speed = program_speed_selection;
          ;
          ;
          lcd_update_running(); // Update LCD running display
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

  menu_flag = false; // Reset menu flag
}

int menu_read_button_pressed() {
  unsigned long debounce = 0;
  if (digitalRead(menu_left)) {
    return left; // Left
    delay(debounce); // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_up)) {
    return up; // Up
    delay(debounce); // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_down)) {
    return down; // Down
    delay(debounce); // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_right)) {
    return right; // Right
    delay(debounce); // Needs a bit of debounce.... (check schmitt trigger)
  }
  else if (digitalRead(menu_run)) {
    delay(debounce); // Needs a bit of debounce.... (check schmitt trigger)
  }
}

void switch_mode() {
  if (mode == 0) { // Program mode
    output_reset(); // Reset outputs
    program_run = false; // Program in Stop mode to begin
    SD_read(program_number); // Load current program
  }
  else if (mode == 1) { // Manual mode
    output_reset(); // Reset outputs
    digitalWrite(manual_swtiches_enable, 0x1); // Enable manual swtichess
  }
  else if (mode == 2) { // Latency test - manual mode
    output_reset(); // Reset outputs
  }
  else if (mode == 3) { // Latency test - automatic mode
    output_reset(); // Reset outputs
  }
}

void manual_mode() {
  static unsigned long manual_time = 0; // Current time 
  static unsigned long manual_update = 100; // 100ms default. Try different values

  if (millis() - manual_time >= manual_update) { // Check if update time has been reached
    for (int i = 0; i < 10; i++) { // 8 speed signals and 2 analog outputs
      int val = analogRead(pots[i]); // Read speed/analog signals
      val = map(val, 0, 1023, 35, 255); // 35 - 255 gives some buffer at each limit        
      if (val <= 41) val = 0; // 4-20ma -> 1-5V -> 41-243 analog write
      else if (val >= 243) val = 243;
      analogWrite(output_pins[i + 8], val); // Output speed/analog signals
      ;
      ;
    }
    ;
  }
}

void program_mode() { // Loop through the number of steps in the program and output brake/speed/analog signals per step in the loop
  const byte wheel_0[] 
# 788 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 788 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = {0, 14, 1, 1, 17, 17, 14, 0};
  const byte wheel_1[] 
# 789 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 789 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = {0, 2, 17, 17, 17, 17, 14, 0};
  const byte wheel_2[] 
# 790 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 790 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = {0, 12, 16, 17, 17, 17, 14, 0};
  const byte wheel_3[] 
# 791 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 791 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = {0, 14, 17, 16, 16, 17, 14, 0};
  const byte wheel_4[] 
# 792 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 792 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = {0, 14, 17, 17, 17, 16, 12, 0};
  const byte wheel_5[] 
# 793 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 793 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = {0, 14, 17, 17, 17, 17, 2, 0};
  const byte wheel_6[] 
# 794 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                      __attribute__((__progmem__)) 
# 794 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                              = {0, 14, 17, 17, 1, 1, 14, 0};
  const byte *wheel[] 
# 795 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                     __attribute__((__progmem__)) 
# 795 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                             = {wheel_0, wheel_1, wheel_2, wheel_3, wheel_4, wheel_5, wheel_6};
  static unsigned long program_time = 0; // Current time 
  static int step = 0; // Current step in program
  static unsigned long loading_time = millis();
  static bool flip = true;
  static bool do_once = true;
  static int index = 0;

  if (millis() - loading_time >= 800 && program_run){ // LCD running animation
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
  else if (!program_run && do_once){ // Clear symbol once program stops running
    lcd.setCursor(11, 0);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 825 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 825 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             " "
# 825 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 825 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    do_once = false;
  }

  if (program_run && !do_once) do_once = true; // Reset flag

  if (program_run) { // Check if START/STOP button is pressed (Run program)
    if (millis() - program_time >= program_speed) { // Check if update time has been reached. Time interval can be changed by user via menu, this is an option
      int val_int;
      char val_char[3] = {'0', '0', '0'};

      for (int n = 0; n < 8; n++) { // Brake signal digital outputs. Number of brake signals. 
        val_char[2] = data[step][n]; // Read brake signal from program data
        val_int = atoi(val_char);
        digitalWrite(output_pins[n], val_int);
      }
      for (int m = 0; m < 10; m++) { // Speed signal & analog outputs. Number of signals = 10
        for (int p = 0; p < 3; p++) {
          val_char[p] = data[step][p + 3 * m + 8]; // Read speed signal from program data
        }
        val_int = atoi(val_char);
        ;
        ;
        val_int = calibrate_output(val_int);
        ;
        analogWrite(output_pins[m + 8], val_int);
      }

      step++;
      if (step == data_steps) {
        step = 0;
        if (!program_loop) {
          program_run = false;
          delay(program_speed); // ****** change to while < speed & !menuflag
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
  if (latency_run){ // Start test button was pressed
    latency_test(); // Run test one time

    latency_run = false; // Reset flag

    latency_running_state(); // Update LCD display with "paused"
  }
}

void latency_automatic() {
  static unsigned long offset = random(0, 5000); // 0 - 5 second delay
  static unsigned long previous_time = millis();

  if (latency_run){ // Start test button pressed
    if (millis() - previous_time > 5000 + offset){ // Run test every 5 seconds + random offset time
      latency_test(); // Run test

      offset = random(0, 5000); // New random offset
      previous_time = millis(); // Record time
    }
  }
}

void latency_test(){
  unsigned long start_time;
  unsigned long latency_time;
  unsigned long timeout = 60000; // 60 000ms = 1 min
  bool no_response = false;

  latency_running_state();

  start_time = millis(); // Test start time

  digitalWrite(latency_led, 0x1); // Turn on LED

  while (millis() - start_time < timeout && digitalRead(adam_do_0) == 0x1){} // Wait for PTI software to trigger ADAM6050 module or for test to timeout

  latency_time = millis() - start_time; // Record test finish time

  if (millis() - start_time >= timeout) no_response = true;

  digitalWrite(latency_led, 0x0); // Turn off LED

  if (no_response) latency_no_response(); // LCD display no response
  else latency_result(latency_time); // LCD show latency time
}

void latency_running_state(){
  if (latency_run){
    lcd.setCursor(0,3);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 940 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 940 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "RUNNING"
# 940 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 940 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
  else{
    lcd.setCursor(0,3);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 944 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 944 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "PAUSED "
# 944 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 944 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
  }
}

void latency_no_response(){
  lcd.setCursor(0,2);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 950 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 950 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "                    "
# 950 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 950 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  lcd.setCursor(0,2);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 952 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 952 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "NO RESPONSE"
# 952 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 952 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
}

void latency_result(long time){
  lcd.setCursor(0,2);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 957 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 957 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "Latency:            "
# 957 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 957 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  lcd.setCursor(9,2);
  lcd.print(time);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 960 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 960 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "ms"
# 960 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 960 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
}

void output_reset() { // Turn off all MOSFET swtiches from program mode, and set speed signals to zero
  for (int i = 0; i < 8; i++) { // 8 brake signals
    digitalWrite(output_pins[i], 0x0); // Turn of brake signals
  }
  for (int n = 0; n < 10; n++) { // 8 speed signals, 2 analog signals
    analogWrite(output_pins[n + 8], 0); // Turn off speed signals
  }
  digitalWrite(manual_swtiches_enable, 0x0); // Disable manual switches
  digitalWrite(latency_led, 0x0); // Turn on LED
}

void SD_write() { // Write data to SD card
if (program_number != 0){ // Program 0 can not be removed
    char file_name[7] = {'0', '0', '.', 't', 'x', 't'}; // Defualt file name
    String str;
    str = String(program_number); // Convert program number to string
    if (program_number < 10) file_name[1] = str[0]; // Update file name 
    else {
      file_name[0] = str[0];
      file_name[1] = str[1];
    }

    SD.remove(file_name); // Remove file

    my_file = SD.open(file_name, (O_READ | O_WRITE | O_CREAT | O_APPEND)); // Create program 0

    if (my_file) {
      my_file.print(file_name[0]); // Program #
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
      ;
      my_file.print(prog_speed); // Program speed. Step time [ms]
      my_file.print('\n');

      for (int i = 0; i < data_steps; i++){ // Step data
        for (int x = 0; x < 38; x++){
          my_file.print(data[i][x]);
        }
        my_file.print('\n');
      }

      my_file.print('\n');
      my_file.print(description); // Program description

      my_file.close();

      ;
    }
    else {
      ;
    }
  }
  else{
    lcd.clear();
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1039 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1039 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "PROGRAM 0 CAN"
# 1039 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 1039 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    lcd.setCursor(0,1);
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1041 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1041 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "NOT BE MODIFIED"
# 1041 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 1041 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    delay(2000);
    lcd_update_running();
  }
}

void SD_read(int program_num) { // Read and process data. program_number = selcted program (1, 2, 3....)
  char file_name[7] = {'0', '0', '.', 't', 'x', 't'}; // Defualt file name
  String str;
  str = String(program_num); // Convert program number to string
  if (program_num < 10) file_name[1] = str[0]; // Update file name 
  else {
    file_name[0] = str[0];
    file_name[1] = str[1];
  }

  ;
  ;

  my_file = SD.open(file_name); // Open selected program number
  if (my_file) {
    bool meta_info = true;
    int SD_step = 0; // Current step being read by SD card. What line (row) in txt file
    int index = 0; // Current index within step array
    char val; // Val to store incoming char
    data_steps = 0; // Reset the number of steps in current program
    char program_num_char[2] = {}; // Read and save program number. First two bytes in file
    char program_spd_char[4] = {}; // Read and save program number. First two bytes in file
    bool new_line = false;

    while (my_file.available()) {
      val = my_file.read(); // Read next byte from txt file
      if (val != '\n') { // Read data line by line and save data as steps
        if (SD_step == 0) { // Save program number data
          program_num_char[index] = val;
          index++;
        }
        else if (SD_step == 1) { // Save program speed data
          program_spd_char[index] = val;
          index++;
        }
        else { // Save step data data
          data[data_steps][index] = val;
          index++;
        }
        new_line = false;
      }
      else if (new_line){ // Blank line was read, this indicates end of data, start of description
        index = 0;
        while (my_file.available()){ // Read the rest of the file
          val = my_file.read();
          if (val == '+') val = ' ';
          description[index] = val;
          index++;
        }
        ;
        ;
        break;
      }
      else { // New line reached
        new_line = true;

        ;
        ;

        if (SD_step == 0) {
          program_number = atoi(program_num_char); // Convert data to int
          ;
        }
        else if (SD_step == 1) {
          program_speed = atoi(program_spd_char); // Convert data to int
          ;
        }
        else {




          data_steps++;
        }
        SD_step++; // Advance to next line on SD card
        index = 0; // Reset "cursor" to first value of SD line
      }
    }
    my_file.close();
    ;
    ;
  }
  else {
    lcd.clear();
    lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1131 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1131 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             "Program Not Found"
# 1131 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
             ); &__c[0];}))
# 1131 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
             )));
    delay(3500);
    SD_read(0); // Error, so load default program
  }
  lcd_update_running(); // Update LCD
}

void menu_pressed() { // External interrupt triggered when any menu or start/stop button is pressed
  menu_flag = true;
}

void ethernet(){
  EthernetClient client = server.available(); // listen for incoming clients

  if (client) {
    ;

    boolean currentLineIsBlank = true; // an http request ends with a blank line

    ;
    ;
    int index = 0;
    readString = ""; // Reset readString
    while (client.available()) {
      char c = client.read();




      if (index > 595) readString += c; // Store incoming data from http client. Start after HTML data
      // if (index > 450) readString += c;                         // Store incoming data from http client. Start after HTML data

      if (c == '\n' && currentLineIsBlank) { // if you've gotten to the end of the line (received a newline character) and the line is blank, the http request has ended, so you can send a reply
        client.println("HTTP/1.1 200 OK"); // send a standard http response header
        client.println("Content-Type: text/html");
        // client.println("Connection: keep-alive");
        client.println("Connection: close");
        client.println();
        // print favicon
      }

      else if (c == '\n') {
        currentLineIsBlank = true; // you're starting a new line
      }
      else if (c != '\r') {
        currentLineIsBlank = false; // you've gotten a character on the current line
      }

      index++;
    }
    ;
    ;
    ;
    ;
    ;
    ;

    decode_ethernet(client); // Decode readString

    readString = ""; // Reset readString
  }
  client.stop(); // Disconnect from client
}

void decode_ethernet(EthernetClient client){
  ;

  static bool first_html = true; // Load main.html the first time the client is connected
  bool save_flag;

  const String step_names[] 
# 1201 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                           __attribute__((__progmem__)) 
# 1201 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                                   = { "step_0_data", "step_1_data", "step_2_data", "step_3_data", "step_4_data", "step_5_data", "step_6_data", "step_7_data", "step_8_data", "step_9_data",
        "step_10_data", "step_11_data", "step_12_data", "step_13_data", "step_14_data", "step_15_data", "step_16_data", "step_17_data", "step_18_data", "step_19_data" };

  if (first_html) {
    ;
    update_html(client, 0, 0); // Load main.html
    first_html = false;
    return;
  }

  if (readString.indexOf("program=") > 0){ // Read the program number being uploaded from html page
    int index = readString.indexOf("program=");
    String val = readString.substring(index + 8, index + 8 + 2); // 8 = length of "program=" string
    if (val[0] != '&') { // Check if number was saved. & = no number in input box
      if (val[1] == '&'){ // Val < 10. ex 1 -> 1&
        val[1] = val[0]; // convert val 1& -> 01
        val[0] = '0';
      }
      program_number = val.toInt();
      ;
      ;
      ;

      if (program_number == 0) return; // Can not edit program 0, defualt program

      char file_name[7] = {val[0], val[1], '.', 't', 'x', 't'}; // File name with selected program number
      my_file = SD.open(file_name);
      if (my_file){ // check if program # already exists on SD card
        // save_flag = lcd_overwrite_program(val);                               // if exisits, overwrite yes/no?. Choice is made on html ui
        save_flag = true;
      }
      else {
        ;
        save_flag = true;
      }

      if (!save_flag){ // no -> update html to show no save
        ;
      }
    }
    else { // No number was in html input box
      save_flag = false;
      ;
    }


    if (save_flag){ // if continue flag, proceed with for loop below
      if (readString.indexOf("speed=") > 0){ // Extract speed value
        int index = readString.indexOf("speed=");
        String val = readString.substring(index + 6, index + 6 + 4); // 6 = length of "speed=" string
        if (val[0] != '&') { // Check if number was saved. & = no number in input box
          if (val[1] == '&'){ // Val < 10. ex 1 -> 1&
            val[3] = val[0]; // convert val 1&tp -> 0001
            val[2] = '0';
            val[1] = '0';
            val[0] = '0';
          }
          else if (val[2] == '&'){ // 10 < Val < 100. ex 10 -> 10&
            val[3] = val[1];
            val[2] = val[0]; // convert val 10&s -> 0010
            val[1] = '0';
            val[0] = '0';
          }
          else if (val[3] == '&'){ // 100 < Val < 1000. ex 100& -> 0100
            val[3] = val[2];
            val[2] = val[1];
            val[1] = val[0]; // convert val 10& -> 0100
            val[0] = '0';
          }
          program_speed = val.toInt();
          ;
          ;
          ;
        }
        else program_speed = 1000; // No speed inputed, default to 1000ms step time
      }

      data_steps = 0; // Reset step count. New program will be loaded
      for (int i = 0; i < 20; i++){ // Loop through all possible steps from html page
        if (readString.indexOf(step_names[i]) > 0){ // > 0 if data exists
          int index = readString.indexOf(step_names[i]);
          String val = readString.substring(index + 12, index + 12 + 38); // 12 = length of "step_x_data=" string
          for (int x = 0; x < 38; x++){ // Save data to data_step_i variables
            data[i][x] = val[x];
            ;
          }
          ;
          data_steps++; // Increase step count
        }
      }

      if (readString.indexOf("description=") > 0){ // Extract program description
        int index = readString.indexOf("description=");
        String val = readString.substring(index + 12, readString.indexOf("program=")-1); // 12 = length of "description=" string
        for (int i = 0; i < 100; i++){ // Reset the description
          description[i] = '\0';
        }
        for (int i = 0; i < val.length(); i++){ // Copy description received from client
          description[i] = val[i];
        }
        ;
      }

      SD_write(); // Save program to SD card. SD_write()
      SD_read(program_number); // Read and load new program

      list_files(client_null, false); // Update program list
      ;
    }

    ;
    ;
    update_html(client, 0, 0); // Update html with current program settings
  }

  else if (readString.indexOf("list_form=") > 0){
    ;
    ;
    update_html(client, 1, 0); // Load list.html 
  }
  else if (readString.indexOf("load_main=") > 0){
    ;
    ;
    list_files(client_null, false); // Update program list
    update_html(client, 0, 0); // Load list.html 
    ;
    ;
  }
  else if (readString.indexOf("program_load=") > 0){ // Update descriptions from list.html page
    ;
    ;
    list_files(client_null, false); // Update program list
    load_program(client); // Load selected program
  }
  else if (readString.indexOf("delete=") > 0){ // Delete selected program
    ;
    ;
    ;
    delete_program();
    list_files(client_null, false);
    if (readString.indexOf("list=") > 0) update_html(client, 1, 0); // Delete called from SAVED PROGRAMS page
    else update_html(client, 0, 0); // Delete called from main page
  }
  else{
    update_html(client, 0, 0); // Load main.html, page refesh
  }
  ;
}

void update_html(EthernetClient client, int page, int count){
  ;
  if (page == 0){ // main.html
    my_file = SD.open("htmlA.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      ;
      my_file.close();
    }
    else ;
    // get sorted list of saved files
    // print list to hidden text input
    // print number followed by - ie 01-02-...
    // list_files(client_null, false);
    client.print(program_list_string);
    //
    my_file = SD.open("htmlB.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      ;
      my_file.close();
    }
    else ;
  }
  else if (page == 1){ // list.html        list of saved programs
    my_file = SD.open("list1.txt"); // open start half html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;

    // print file names and descriptions
    list_files(client, true);

    my_file = SD.open("list2.txt"); // open second half html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
  }
  else if (page == 2){ // Load program
    my_file = SD.open("html1.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
    // Program nuber
    client.print(readString.substring(0,2)); // Program number
    //
    my_file = SD.open("html2.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
    // program speed
    client.print(readString.substring(3,7));
    //
    my_file = SD.open("html3.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
    // step data ui
    for (int i = 0; i < count - 4; i++){ // 4 lines are program number, speed, blank, description
      client.print("<div class='step'>");
      client.print("<div class='step_label'>");
      client.print(i);
      client.print("</div>");

      int index = 8 + i*39; // First char in line
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
    my_file = SD.open("html4.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
    // Description
    bool first = false; // first '\n' , end of file -> '\n' '\n' description
    int index2 = 0; // current char index in readString. Looking for first char in last line
    unsigned long time_out = millis();
    while(1){ // Find index of first char in last line
      char val2 = readString[index2];
      if (val2 != '\n') {
        index2++;
        first = false;
      }
      else if (val2 == '\n' && first == false) { // New line
        index2++;
        first = true;
      }
      else if (val2 == '\n' && first == true) { // Last line       
        index2++;
        break;
      }
      if (millis() - time_out >= 9999){
        ;
        break;
      }
    }
    String str = readString.substring(index2);
    str.replace('+',' '); // Remove all + symbols
    client.print(str); // Print last line
    //
    my_file = SD.open("html5.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
    // step_data_x hidden 
    client.print(readString.substring(0,2)); // Program nuber
    client.print("'>");

    client.print("<input type='text' id='speed' class='hidden' name='speed' value='");
    client.print(readString.substring(3,7)); // Program speed
    client.print("'>");


    for (int i = 0; i < count - 4; i++){ // 4 lines are program number, speed, blank, description
      client.print("<input id='form_data' type='text' name='step_");
      client.print(i);
      client.print("_data' value='");

      int index = 7 + i*39; // First char in line
      for (int i = 0; i < 38; i++) client.print(readString[index + i]);


      client.print("' class='hidden'>");
    }
    //
    my_file = SD.open("html6.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
    // Program list
    // client.print(program_list);                   // TEST data
    client.print(program_list_string);
    //
    my_file = SD.open("html7.txt"); // open html file
    if (my_file){
      ;
      while(my_file.available()){ // Read html file
        char val;
        val = my_file.read();
        client.print(val); // Write html content to browser
      }
      my_file.close();
    }
    else ;
  }
  ;
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

void list_files(EthernetClient client, bool print) { // print = true -> print html content to client. False -> created sorted list
  int index_file = 0;

  program_list_string = "";

  sorted_files_list();

  ;
  // File root = SD.open("/");
  while (true){
    my_file = SD.open(program_list_sorted[index_file]);
    // my_file = root.openNextFile();

    ;
    if (!my_file) break; // no more files

    if (print){
      if (isDigit(my_file.name()[0])){ // Do not read HTML, LIST files, etc. Only program files
        char *str = my_file.name();

        client.print((reinterpret_cast<const __FlashStringHelper *>(
# 1651 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1651 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    "<form method='post' action='/''><input type='submit' value='Load'><input type='button' value='Delete' onclick='delete_program(this.parentNode)''><label>"
# 1651 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    ); &__c[0];}))
# 1651 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    )));
        client.print(str[0]);
        client.print(str[1]);
        client.print((reinterpret_cast<const __FlashStringHelper *>(
# 1654 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1654 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    "</label><label>"
# 1654 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    ); &__c[0];}))
# 1654 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    )));

        int index = 0;
        memset(description, '\0', sizeof(description));
        while (my_file.available()){ // Extract description from current entry
          char val = my_file.read();
          if (val != '\n') { // Read next char
            if (val == '+') val = ' ';
            description[index] = val; // Once last line is read, that will be the description
            index++; // Go to next line
          }
          else {
            index = 0;
            memset(description, '\0', sizeof(description));
          }
        }
        client.print(description);
        client.print((reinterpret_cast<const __FlashStringHelper *>(
# 1671 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1671 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    "</label><input class='hidden' type='text' value='"
# 1671 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    ); &__c[0];}))
# 1671 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    )));
        client.print(str[0]);
        client.print(str[1]);
        client.print((reinterpret_cast<const __FlashStringHelper *>(
# 1674 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1674 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    "' name='program_load'></form>"
# 1674 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                    ); &__c[0];}))
# 1674 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                    )));
      }
    }
    else {
      if (isDigit(my_file.name()[0])) { // Add program numbers only to string of program numbers. HTML file uses this string
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
  ;
  ;

  int max_files = 113; // 101 +  number of html css etc files (12)
  int index = 0;
  int elementCount = 0; // Number of elements in program_list_sorted

  for (int n = 0; n < sizeof(program_list_sorted)/sizeof(program_list_sorted[0]); n++) program_list_sorted[n][0] = '\0'; // Reset the array to null

  File root = SD.open("/"); // Open root directory
  if (root){
    ;

    while (index < max_files){
    File entry = root.openNextFile(); // Loop through files on SD card

    // if (!strlen(str)) {
    if (!entry) {
      break; // No more files                                                  
    }

    char *str = entry.name(); // Save file name pointer

    if (!isDigit(str[0])) { // Don't include html css etc files in sorted list
      entry.close();
      continue;
    }

    strcpy(program_list_sorted[index], str); // Save file name to program_list_sorted

    ;
    entry.close(); // Close file
    index++;
    }

    if (index == max_files)
    {
      ; // Alert user of error
    }
    else
    {
      elementCount = index; // Count number of elements in myWords

      qsort(program_list_sorted, elementCount, sizeof(program_list_sorted[0]), CompareStrings); // Sort elements






    }

    ;
    root.close();
  }
  else ;

  ;
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

int CompareStrings(const void *p1, const void *p2) // Sorting algorithm 
{
  return strcmp(p1, p2);
}

void delete_program(){
  int index = readString.indexOf("delete=");
  int index_end = readString.indexOf("list=");
  ;
  ;
  String val;
  if (index_end > 0) val = readString.substring(index + 7, index_end - 1); // Delete from SAVED PROGRAMS page
  else val = readString.substring(index + 7); // Delete from main page
  ;
  ;
  char file_name[7] = "00.txt"; // Convert readString to file_name
  if (val.length() == 2){
    file_name[0] = val[0];
    file_name[1] = val[1];
  }
  else{
    file_name[0] = '0';
    file_name[1] = val[0];
  }

  SD.remove(file_name); // Delete file

  char temp[] = {file_name[0], file_name[1]};
  String str = String(temp);
  int program = str.toInt();

  if (program = program_number){ // Check if the running file was deleted
    program_run = false; // Running program was deleted so stop running 
    output_reset();
    SD_read(0); // Load default program 0
  }

  ;
  ;
  ;
}

void load_program(EthernetClient client){
  ;
  int index = readString.indexOf("program_load=");
  String val = readString.substring(index + 13);
  ;
  int length = val.length();
  ;
  char file_name[7] = "00.txt"; // Convert readString to file_name
  ;
  if (length < 2) file_name[1] = val[0];
  else{
    file_name[0] = val[0];
    file_name[1] = val[1];
  }
  ;
  my_file = SD.open(file_name); // Try to open program file
  if (my_file) { // Program exists if true
    readString = ""; // Reset readstring
    int count = 0;
    ;
    Serial.print("pre load file ");
    while (my_file.available()){
      char val = my_file.read();
      if (val == '\n') count++;
      readString += val; // Save program data to readstring
    }
    Serial.print("post load file ");
    count++; // Last line of txt does not have \n
    my_file.close();
    ;
    update_html(client, 2, count); // If program is saved on SD, load program
  }
  else ;
}

bool lcd_overwrite_program(String program){
  static int menu_button_pressed; // Variable to store the result of enum
  bool selection = false; // true once user makes selection, ie presses the right button
  bool overwrite = false; // true = overwrite

  lcd.clear();
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1890 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1890 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "Program "
# 1890 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 1890 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  lcd.print(program);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1892 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1892 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           " exists"
# 1892 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 1892 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  lcd.setCursor(0,1);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1894 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1894 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "Overwrite file?"
# 1894 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 1894 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  lcd.setCursor(0,2);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1896 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1896 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "YES"
# 1896 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 1896 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  lcd.setCursor(0,3);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1898 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1898 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "NO"
# 1898 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 1898 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));
  lcd.setCursor(19,3);
  lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1900 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1900 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           "*"
# 1900 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
           ); &__c[0];}))
# 1900 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
           )));

  while (!selection){
    if (menu_flag){ // A button was pressed
      menu_button_pressed = menu_read_button_pressed(); // check which button was pressed
      switch (menu_button_pressed){
      case up: // YES selection
        lcd.setCursor(19,2);
        lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1908 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1908 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 "*"
# 1908 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 ); &__c[0];}))
# 1908 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 )));
        lcd.setCursor(19,3);
        lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1910 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1910 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 " "
# 1910 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 ); &__c[0];}))
# 1910 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 )));
        overwrite = true;
        break;
      case down: // NO selection
        lcd.setCursor(19,2);
        lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1915 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1915 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 " "
# 1915 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 ); &__c[0];}))
# 1915 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 )));
        lcd.setCursor(19,3);
        lcd.print((reinterpret_cast<const __FlashStringHelper *>(
# 1917 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 (__extension__({static const char __c[] __attribute__((__progmem__)) = (
# 1917 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 "*"
# 1917 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino" 3
                 ); &__c[0];}))
# 1917 "c:\\Users\\ryan corkery\\OneDrive - Papertech Inc\\Documents\\_Projects\\GPIO Box\\IO_Bench_Simulator\\IO_Bench_Simulator.ino"
                 )));
        overwrite = false;
        break;
      case right: // Make selection
        selection = true;
        break;
      }
      menu_flag = false;
    }
  }

  lcd_update_running(); // Reset UI

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
