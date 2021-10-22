#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("list1.txt");

  my_file = SD.open("list1.txt", FILE_WRITE);

  if (my_file){
    Serial.println("list1.txt opened successfully");
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
my_file.println(F(""));
my_file.println(F("        <form method='post' action='/'>"));
my_file.println(F("            <input type='submit' name='load_main' value='Return to programming page'>"));
my_file.println(F("        </form>"));
my_file.println(F(""));
my_file.println(F("        <iframe name='iframe' style='display: none;'></iframe>"));
my_file.println(F("        <form method='post' action='/' name='save_descriptions' target='iframe'>"));
my_file.println(F("            <input type='button' onclick='save_descriptions()' value='Save descriptions'>"));
my_file.println(F("        </form>"));
my_file.println(F("        "));
my_file.println(F(""));
my_file.println(F("        <div class='list'>"));
my_file.println(F("            <div class='info'>"));


    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open list1.txt file on SD card");
}


void loop() {
 
}
