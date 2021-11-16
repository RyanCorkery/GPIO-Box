#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("00.txt");

  my_file = SD.open("00.txt", FILE_WRITE);

  if (my_file){
    Serial.println(".txt opened successfully");

    // **** PROGRAM 0 **** //
    my_file.print("00");                                           // Program #

    my_file.print('\n');

    my_file.print("0500");                                      // Program speed. Step time [ms]

    my_file.print('\n');

    my_file.print("10000000242000000000000000000000000000");                          // Program data
    my_file.print('\n');
    my_file.print("01000000000242000000000000000000000000");
    my_file.print('\n');
    my_file.print("00100000000000242000000000000000000000");
    my_file.print('\n');
    my_file.print("00010000000000000242000000000000000000");
    my_file.print('\n');
    my_file.print("00001000000000000000242000000000000000");                        
    my_file.print('\n');
    my_file.print("00000100000000000000000242000000000000");
    my_file.print('\n');
    my_file.print("00000010000000000000000000242000000000");
    my_file.print('\n');
    my_file.print("00000001000000000000000000000242000000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000000242");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000091000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000142000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000192000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000242000");
    my_file.print('\n');
    my_file.print('\n');
    my_file.print("Default test program");
    my_file.close();
  }
  else Serial.println("Failed to open .txt file on SD card");
}


void loop() {
 
}
