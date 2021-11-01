#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("html5.txt");

  my_file = SD.open("html5.txt", FILE_WRITE);

  if (my_file){
    Serial.println("html5.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
my_file.println(F("' id='description' name='description' maxlength='100'>Limit 100 characters<br>"));
my_file.println(F("    <input class='step_button' type='submit' value='Save program'>"));
my_file.println(F("    <input type='text' id='program' class='hidden' name='program' value='"));
//my_file.println(F("    <input type='text' id='program' class='hidden' name='program' value=''>"));
//my_file.println(F("    <input type='text' id='speed' class='hidden' name='speed' value=''>"));

    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html5.txt file on SD card");
}


void loop() {
 
}
