#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("html4.txt");

  my_file = SD.open("html4.txt", FILE_WRITE);

  if (my_file){
    Serial.println("html4.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
//my_file.println(F("        </div>"));
my_file.println(F("    </div>"));
my_file.println(F("</div>"));
my_file.println(F(""));
my_file.println(F("<div>"));
my_file.println(F("<input class='step_button' type='button' value='Add Step' onclick='add_step(false)'>"));
my_file.println(F("<input class='step_button' type='button' value='Duplicate Last Step' onclick='add_step(true)'>"));
my_file.println(F("</div>"));
my_file.println(F("<input class='step_button' type='button' value='Remove Last Step' onclick='remove_step()'>"));
my_file.println(F(""));

my_file.println(F("    <input type='button' value='Delete Program' class='step_button' onclick='delete_program()'>"));

my_file.println(F("<iframe name='iframe1' style='display:none;'></iframe>"));
my_file.println(F("<form id='my_form' method='post' action='/' name='pins' target='iframe1' onsubmit='save_data()'>"));
my_file.println(F("    <label>Program description:</label><input type='text' value='"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html4.txt file on SD card");
}


void loop() {
 
}
