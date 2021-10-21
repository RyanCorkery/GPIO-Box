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
    
    my_file.print(0);                                           // Program #
    my_file.print(0);

    my_file.print('\n');

    my_file.print("500");                                      // Program speed. Step time [ms]

    my_file.print('\n');

    my_file.print("10000000255000000000000000000000000000");                          // Program data
    my_file.print('\n');
    my_file.print("01000000000255000000000000000000000000");
    my_file.print('\n');
    my_file.print("00100000000000255000000000000000000000");
    my_file.print('\n');
    my_file.print("00010000000000000255000000000000000000");
    my_file.print('\n');
    my_file.print("00001000000000000000255000000000000000");                        
    my_file.print('\n');
    my_file.print("00000100000000000000000255000000000000");
    my_file.print('\n');
    my_file.print("00000010000000000000000000255000000000");
    my_file.print('\n');
    my_file.print("00000001000000000000000000000255000000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000000255");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000100000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000150000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000200000");
    my_file.print('\n');
    my_file.print("00000000000000000000000000000000250000");
    my_file.print('\n');
  
    my_file.close();
  }
  else Serial.println("Failed to open .txt file on SD card");
}


void loop() {
 
}
