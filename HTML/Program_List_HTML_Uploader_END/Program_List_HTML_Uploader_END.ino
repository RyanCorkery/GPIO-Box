#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("list2.txt");

  my_file = SD.open("list2.txt", FILE_WRITE);

  if (my_file){
    Serial.println("list2.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //

my_file.println(F("            </div>"));
my_file.println(F("        </div>"));
my_file.println(F(""));
my_file.println(F("        <script>"));
my_file.println(F("            function read_url(){"));
my_file.println(F("                const urlSearchParams = new URLSearchParams(window.location.search);"));
my_file.println(F("                for (const val of urlSearchParams.values()){"));
my_file.println(F("                    document.getElementById('file_names').innerHTML = val;"));
my_file.println(F("                }"));
my_file.println(F("            }"));
my_file.println(F(""));
//my_file.println(F("            function load_main(){"));
//my_file.println(F("                window.location = 'Main.html';"));
//my_file.println(F("            }"));
my_file.println(F(""));
//my_file.println(F("            function save_descriptions(){"));
//my_file.println(F("                   add code"));
//my_file.println(F("            }"));
my_file.println(F("        </script>"));
my_file.println(F("    </body>"));
my_file.println(F("</html>"));

    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open list2.txt file on SD card");
}


void loop() {
 
}
