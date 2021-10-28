#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("html2.txt");

  my_file = SD.open("html2.txt", FILE_WRITE);

  if (my_file){
    Serial.println("html2.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
my_file.println(F("' onchange='update_program_number()'></div>"));
my_file.println(F("    <div class='program'><label>Program Speed:</label><input id='speed_ui' value='"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html2.txt file on SD card");
}


void loop() {
 
}
