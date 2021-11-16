#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("html3.txt");

  my_file = SD.open("html3.txt", FILE_WRITE);

  if (my_file){
    Serial.println("html3.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
my_file.println(F("' onchange='update_program_speed(this)'>[ms], period of each step</div>"));
my_file.println(F("    <div id='step_inputs'>"));
my_file.println(F("        <div class='Labels'>"));
my_file.println(F("            <div id='step_title'>Step #</div>"));
my_file.println(F("            <div>Break 1</div>"));
my_file.println(F("            <div>Break 2</div>"));
my_file.println(F("            <div>Break 3</div>"));
my_file.println(F("            <div>Break 4</div>"));
my_file.println(F("            <div>Break 5</div>"));
my_file.println(F("            <div>Break 6</div>"));
my_file.println(F("            <div>Break 7</div>"));
my_file.println(F("            <div>Break 8</div>"));
my_file.println(F("            <div>Speed 1</div>"));
my_file.println(F("            <div>Speed 2</div>"));
my_file.println(F("            <div>Speed 3</div>"));
my_file.println(F("            <div>Speed 4</div>"));
my_file.println(F("            <div>Speed 5</div>"));
my_file.println(F("            <div>Speed 6</div>"));
my_file.println(F("            <div>Speed 7</div>"));
my_file.println(F("            <div>Speed 8</div>"));
my_file.println(F("            <div>Analog 1</div>"));
my_file.println(F("            <div>Analog 2</div>"));
my_file.println(F("        </div>"));
//my_file.println(F("        <div id='step_0' class='step'>"));
//my_file.println(F("            <div class='step_label'>0</div>"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html3.txt file on SD card");
}


void loop() {
 
}
