#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("save.txt");

  my_file = SD.open("save.txt", FILE_WRITE);

  if (my_file){
    Serial.println("save.txt opened successfully");
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
my_file.println(F("            flex-direction: column;"));
my_file.println(F("        }"));
my_file.println(F("        .info > p > input{"));
my_file.println(F("            margin-left: 30px;"));
my_file.println(F("        }"));
my_file.println(F("    </style>"));
my_file.println(F("    <head>"));
my_file.println(F(""));
my_file.println(F("    </head>"));
my_file.println(F("    <!-- <body onload='read_url()'> -->"));
my_file.println(F("    <body>"));
my_file.println(F("        <h1>SAVED PROGRAMS</h1>"));
my_file.println(F("        <p>This program exists. Overwrite? Make selection on IO box</P>"));
my_file.println(F("    </body>"));
my_file.println(F("    </html>"));

    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open save.txt file on SD card");
}


void loop() {
 
}
