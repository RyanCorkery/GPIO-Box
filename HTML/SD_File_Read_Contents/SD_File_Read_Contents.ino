#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("01.txt");
  SD.remove("02.txt");
  SD.remove("03.txt");
  SD.remove("04.txt");
  SD.remove("05.txt");
  SD.remove("10.txt");
  
  my_file = SD.open("02.txt");

  if (my_file){
    while (my_file.available()){
      char c = my_file.read();
      Serial.print(c);
    }
  
    my_file.close();
  }
  else Serial.println("Failed to open .txt file on SD card");
}


void loop() {
 
}
