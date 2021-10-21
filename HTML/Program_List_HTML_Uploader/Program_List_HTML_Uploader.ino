#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

//  SD.remove("program_list.txt");

  my_file = SD.open("list.txt", FILE_WRITE);

  if (my_file){
    Serial.println("list.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
my_file.println(F("<html>"));
my_file.println(F("    <style>"));
my_file.println(F("        h1{"));
my_file.println(F("            text-align: center;"));
my_file.println(F("            border-bottom: 2px solid darkslategray;"));
my_file.println(F("        }"));
my_file.println(F("        .info{"));
my_file.println(F("            display: flex;"));
my_file.println(F("            flex-direction: row;"));
my_file.println(F("        }"));
my_file.println(F("        #file_names{"));
my_file.println(F("            margin-right: 40px;"));
my_file.println(F("        }"));
my_file.println(F("    </style>"));
my_file.println(F("    <head>"));
my_file.println(F(""));
my_file.println(F("    </head>"));
my_file.println(F("    <body onload='read_url()'>"));
my_file.println(F("        <h1>SAVED PROGRAMS</h1>"));
my_file.println(F(""));
my_file.println(F("        <input type='button' onclick='load_main()' value='Return to programming page'>"));
my_file.println(F(""));
my_file.println(F("        <div class='list'>"));
my_file.println(F("            <div class='info'>"));
my_file.println(F("                <div>"));
my_file.println(F("                    <p id='file_names'></p>"));
my_file.println(F("                </div>"));
my_file.println(F("                <div>"));
my_file.println(F("                    <!-- Add abillity to add comments -->"));
my_file.println(F("                    <p id='file_descriptions'>Default program<br><br></p>           "));
my_file.println(F("                </div>"));
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
my_file.println(F("            function load_main(){"));
my_file.println(F("                window.location = 'Main.html';"));
my_file.println(F("            }"));
my_file.println(F("        </script>"));
my_file.println(F("    </body>"));
my_file.println(F("</html>"));

    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open program_list.txt file on SD card");
}


void loop() {
 
}
