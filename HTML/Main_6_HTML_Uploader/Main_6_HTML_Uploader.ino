#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("html6.txt");

  my_file = SD.open("html6.txt", FILE_WRITE);

  if (my_file){
    Serial.println("html6.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
//my_file.println(F("    <input id='form_data' type='text' name='step_0_data' value='00000000000000000000000000000000000000' class='hidden'>"));
my_file.println(F("</form>"));
my_file.println(F(""));
my_file.println(F("<input type='text' id='program_list' class='hidden' value='"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html6.txt file on SD card");
}


void loop() {
 
}
