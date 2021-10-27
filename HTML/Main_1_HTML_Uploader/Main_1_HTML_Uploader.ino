#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("html1.txt");

  my_file = SD.open("html1.txt", FILE_WRITE);

  if (my_file){
    Serial.println("html1.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
my_file.println(F("<html>"));
my_file.println(F("<head>"));
my_file.println(F("<meta http-equiv='Content-Language' content='nl'>"));
my_file.println(F("<meta http-equiv='Content-Type' content='text/html; charset=windows-1252'>"));
my_file.println(F("<title>GPIO Box REV 2</title>"));
my_file.println(F("<style>"));
my_file.println(F("body{"));
my_file.println(F("    display: flex;"));
my_file.println(F("    flex-direction: column;"));
my_file.println(F("}"));
my_file.println(F("h1 { "));
my_file.println(F("    text-align: center;"));
my_file.println(F("    border-bottom: 2px solid darkslategray;"));
my_file.println(F("}"));
my_file.println(F(".grid-container{"));
my_file.println(F("    padding: 15px;"));
my_file.println(F("    display: grid;"));
my_file.println(F("    justify-content: start;"));
my_file.println(F("    grid-gap: 10px;"));
my_file.println(F("    grid-template-columns: auto;"));
my_file.println(F("}"));
my_file.println(F(".grid-container > div{"));
my_file.println(F("    display: grid;"));
my_file.println(F("    grid-auto-flow: column;"));
my_file.println(F("    justify-content: left;"));
my_file.println(F("}"));
my_file.println(F(".labels > div{"));
my_file.println(F("    padding: 5px;"));
my_file.println(F("    width: 70px;"));
my_file.println(F("    height: 20px;"));
my_file.println(F("}"));
my_file.println(F(".step{"));
my_file.println(F("    border-left: 1px solid cadetblue;"));
my_file.println(F("}"));
my_file.println(F(".step_label, #step_title{"));
my_file.println(F("    border-bottom: 2px solid gray;"));
my_file.println(F("}"));
my_file.println(F(".step > div{"));
my_file.println(F("    margin: 0 0 0 0;"));
my_file.println(F("    padding: 5px;"));
my_file.println(F("    height: 20px;"));
my_file.println(F("    width: auto;"));
my_file.println(F("}"));
my_file.println(F(".step_label{"));
my_file.println(F("    text-align: center;"));
my_file.println(F("}"));
my_file.println(F(".step > div > input{"));
my_file.println(F("    width: 35px;"));
my_file.println(F("    margin: auto;"));
my_file.println(F("}"));
my_file.println(F("#my_form{"));
my_file.println(F("    display: flex;"));
my_file.println(F("    flex-direction: column;"));
my_file.println(F("}"));
my_file.println(F("#form_data{"));
my_file.println(F("    width: 500px;;"));
my_file.println(F("}"));
my_file.println(F(".step_button{"));
my_file.println(F("    width: 200px;"));
my_file.println(F("    margin: 5px;"));
my_file.println(F("}"));
my_file.println(F(".hidden{"));
my_file.println(F("    visibility: hidden;"));
my_file.println(F("}"));
my_file.println(F(".program{"));
my_file.println(F("    margin: 5px;"));
my_file.println(F("}"));
my_file.println(F("#program_ui{"));
my_file.println(F("    margin-left: 10px;"));
my_file.println(F("    width: 30px;"));
my_file.println(F("}"));
my_file.println(F("#speed_ui{"));
my_file.println(F("    margin-left: 22px;"));
my_file.println(F("    width: 50px;"));
my_file.println(F("}"));
my_file.println(F(".step_label{"));
my_file.println(F("    margin-left: 15px;"));
my_file.println(F("}"));
my_file.println(F("#description{"));
my_file.println(F("    margin: 5px;"));
my_file.println(F("    display: flex;"));
my_file.println(F("    width: auto;"));
my_file.println(F("}"));
my_file.println(F("</style>"));
my_file.println(F("</head>"));
my_file.println(F(""));
my_file.println(F(""));
my_file.println(F("<body>"));
my_file.println(F(""));
my_file.println(F("<h1>GPIO BOX REV 2</h1>"));
my_file.println(F(""));
my_file.println(F("<form id='list_form' method='post' action='/'>"));
my_file.println(F("    <input type='submit' name='list_form' value='Click to view the list of saved programs'>"));
my_file.println(F("</form>"));
//my_file.println(F("<iframe name='program_iframe' style='display: none;'></iframe>"));
my_file.println(F("<form id='program_load' method='post' action='/' style='display: none;'>"));
my_file.println(F("    <input type='text' value='' id='program_submit' name='program_load'>"));
my_file.println(F("    <input type='submit'>"));
my_file.println(F("</form>"));
my_file.println(F(""));
my_file.println(F("<div class='grid-container'>"));
my_file.println(F("    <div class='program'>Program Number: <input id='program_ui' value='"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html1.txt file on SD card");
}


void loop() {
 
}
