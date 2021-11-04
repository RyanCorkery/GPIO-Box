#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }


  
  my_file = SD.open("03.txt");

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
