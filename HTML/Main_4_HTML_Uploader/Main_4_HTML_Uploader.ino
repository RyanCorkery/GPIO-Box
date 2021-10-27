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
my_file.println(F("<input class='step_button' type='button' value='Add Step' onclick='add_step()'>"));
my_file.println(F("<input class='step_button' type='button' value='Remove Step' onclick='remove_step()'><br>"));
my_file.println(F(""));
my_file.println(F("<form id='delete_form' method='post' action='/'>"));
my_file.println(F("    <input type='submit' value='Delete Program' class='step_button'>"));
my_file.println(F("    <input type='text' id='program_number_delete' value='' name='delete_program' hidden>"));
my_file.println(F("</form>"));
my_file.println(F("<iframe name='iframe1' style='display:none;'></iframe>"));
my_file.println(F("<form id='my_form' method='post' action='/' name='pins' target='iframe1' onsubmit='save_data()'>"));
my_file.println(F("    Program description:<input type='text' value='"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html4.txt file on SD card");
}


void loop() {
 
}
