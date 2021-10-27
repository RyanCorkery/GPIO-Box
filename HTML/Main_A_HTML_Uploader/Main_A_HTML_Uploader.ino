#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("htmlA.txt");

  my_file = SD.open("htmlA.txt", FILE_WRITE);

  if (my_file){
    Serial.println("htmlA.txt opened successfully");
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
my_file.println(F(""));
//my_file.println(F("<iframe name='program_iframe' style='display: none;'></iframe>"));
my_file.println(F("<form id='program_load' method='post' action='/' style='display: none;'>"));
my_file.println(F("    <input type='text' value='' id='program_submit' name='program_load'>"));
my_file.println(F("    <input type='submit'>"));
my_file.println(F("</form>"));
my_file.println(F(""));
my_file.println(F("<div class='grid-container'>"));
my_file.println(F("    <div class='program'>Program Number: <input id='program_ui' value='' onchange='update_program_number()'></div>"));
my_file.println(F("    <div class='program'>Program Speed:  <input id='speed_ui' value='' onchange='update_program_speed()'></div>"));
my_file.println(F("    <div id='step_inputs'>"));
my_file.println(F("        <div class='Labels'>"));
my_file.println(F("            <div id='step_title'>Step #</div>"));
my_file.println(F("            <div>Break 1</div>"));
my_file.println(F("            <div>Break 2</div>"));
my_file.println(F("            <div>Break 3</div>"));
my_file.println(F("            <div>Break 4</div>"));
my_file.println(F("            <div>Break 5</div>"));
my_file.println(F("            <div>Break 6</div>"));
my_file.println(F("            <div>Break 7</div>"));
my_file.println(F("            <div>Break 8</div>"));
my_file.println(F("            <div>Speed 1</div>"));
my_file.println(F("            <div>Speed 2</div>"));
my_file.println(F("            <div>Speed 3</div>"));
my_file.println(F("            <div>Speed 4</div>"));
my_file.println(F("            <div>Speed 5</div>"));
my_file.println(F("            <div>Speed 6</div>"));
my_file.println(F("            <div>Speed 7</div>"));
my_file.println(F("            <div>Speed 8</div>"));
my_file.println(F("            <div>Analog 1</div>"));
my_file.println(F("            <div>Analog 2</div>"));
my_file.println(F("        </div>"));
my_file.println(F("        <div id='step_0' class='step'>"));
my_file.println(F("            <div class='step_label'>0</div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='checkbox'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("            <div><input type='text' value='0'></div>"));
my_file.println(F("        </div>"));
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
my_file.println(F("    Program description:<input type='text' value='' id='description' name='description' maxlength='100'>Limit 100 characters<br>"));
my_file.println(F("    <input class='step_button' type='submit' value='Save program'>"));
my_file.println(F("    <input type='text' id='program' class='hidden' name='program'>"));
my_file.println(F("    <input type='text' id='speed' class='hidden' name='speed'>"));
my_file.println(F("    <input id='form_data' type='text' name='step_0_data' value='00000000000000000000000000000000000000' class='hidden'>"));
my_file.println(F("</form>"));
my_file.println(F(""));



my_file.println(F("<input type='text' id='program_list' class='hidden' value='"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open htmlA.txt file on SD card");
}


void loop() {
 
}
