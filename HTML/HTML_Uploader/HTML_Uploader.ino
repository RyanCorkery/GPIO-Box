#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("html.txt");

  my_file = SD.open("html.txt", FILE_WRITE);

  if (my_file){
    Serial.println("html.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
 my_file.println(F("<html>"));
my_file.println(F("<head>"));
my_file.println(F("<meta http-equiv='Content-Language' content='nl'>"));
my_file.println(F("<meta http-equiv='Content-Type' content='text/html; charset=windows-1252'>"));
my_file.println(F("<title>GPIO Box REV 2</title>"));
my_file.println(F("<style>"));
my_file.println(F("h1 { "));
my_file.println(F("    text-align: center;"));
my_file.println(F("}"));
my_file.println(F(".grid-container{"));
my_file.println(F("    padding: 15px;"));
my_file.println(F("    display: grid;"));
my_file.println(F("    justify-content: start;"));
my_file.println(F("    grid-gap: 10px;"));
my_file.println(F("    /* grid-auto-flow: column; */"));
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
my_file.println(F(".step > div{"));
my_file.println(F("    padding: 5px;"));
my_file.println(F("    height: 20px;"));
my_file.println(F("    width: 50px;"));
my_file.println(F("}"));
my_file.println(F(".step > div > input{"));
my_file.println(F("    width: 35px;"));
my_file.println(F("}"));
my_file.println(F("#form_data{"));
my_file.println(F("    width: 500px;;"));
my_file.println(F("}"));
my_file.println(F(".hidden{"));
my_file.println(F("    /* visibility: hidden; */"));
my_file.println(F("}"));
my_file.println(F(".program{"));
my_file.println(F("    margin: 5px;"));
my_file.println(F("}"));
my_file.println(F("#program_ui{"));
my_file.println(F("    margin-left: 10px;"));
my_file.println(F("    width: 30px;"));
my_file.println(F("}"));
my_file.println(F("</style>"));
my_file.println(F("</head>"));
my_file.println(F(""));
my_file.println(F(""));
my_file.println(F("<body>"));
my_file.println(F(""));
my_file.println(F("<h1>GPIO Box REV 2</h1>"));
my_file.println(F(""));
my_file.println(F("<div class='grid-container'>"));
my_file.println(F("    <div class='program'>Program Number: <input id='program_ui' onchange='update_program_number()'></div>"));
my_file.println(F("    <div id='step_inputs'>"));
my_file.println(F("        <div class='Labels'>"));
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
my_file.println(F("<input type='button' value='Add Step' onclick='add_step()'>"));
my_file.println(F("<input type='button' value='Remove Step' onclick='remove_step()'><br><br>"));
my_file.println(F(""));
my_file.println(F("<form id='my_form' method='post' action='' name='pins' onsubmit='save_data()'>"));
my_file.println(F("    <input type='submit' value='Save program'>"));
my_file.println(F("    <input type='text' id='program' class='hidden' name='program'>"));
my_file.println(F("    <input id='form_data' type='text' name='step_0_data' value='00000000000000000000000000000000000000' class='hidden'>"));
my_file.println(F("</form>"));
my_file.println(F(""));
my_file.println(F("<input type='button' onclick='save_data()'>"));
my_file.println(F(""));
my_file.println(F("<script>"));
my_file.println(F("    function save_data(){"));
my_file.println(F("        var number_of_steps = document.getElementById('step_inputs').children.length - 1;                                                              "));
my_file.println(F(""));
my_file.println(F("        var inputs = document.getElementById('step_inputs');                                                                                                                                  "));
my_file.println(F("        inputs = inputs.getElementsByTagName('input');"));
my_file.println(F("        var value;                                                                                                                                          "));
my_file.println(F(""));
my_file.println(F("        for (var x = 0; x < number_of_steps; x++){                                                                                       "));
my_file.println(F("            var original = document.getElementById('form_data').value;                                                                       '                                      '"));
my_file.println(F("            for (var i = 0; i < 8; i++) {                                                                                                                        "));
my_file.println(F("                if (inputs[i+x*18].type === 'checkbox') {"));
my_file.println(F("                    if (inputs[i+x*18].checked){                                                                                                               "));
my_file.println(F("                        value = inputs[i+x*18].value;    "));
my_file.println(F("                        original = replaceChar(original, '1', i);"));
my_file.println(F("                                                   '       '                                 "));
my_file.println(F("                    }   "));
my_file.println(F("                }"));
my_file.println(F("            }"));
my_file.println(F("            for (var i = 0; i < 10; i++) {                                                                                                                                  "));
my_file.println(F("                if (inputs[i+x*18+8].type === 'text') {"));
my_file.println(F("                    value = inputs[i+x*18+8].value;                                                                                       "));
my_file.println(F("                    "));
my_file.println(F("                    for (var n = 2; n>=0; n--){                                                                                                           "));
my_file.println(F("                        if (value[n]){                                                                                                                         "));
my_file.println(F("                            original = replaceChar(original, value[n], i*3+8+n);"));
my_file.println(F("                        }"));
my_file.println(F("                    }"));
my_file.println(F("                }"));
my_file.println(F("            }"));
my_file.println(F("            document.getElementById('my_form').children[x+2].value = original;"));
my_file.println(F("        }"));
my_file.println(F("    }"));
my_file.println(F(""));
my_file.println(F("    function replaceChar(origString, replaceChar, index) {"));
my_file.println(F("        let firstPart = origString.substr(0, index);"));
my_file.println(F("        let lastPart = origString.substr(index + 1);"));
my_file.println(F("        "));
my_file.println(F("        let newString = firstPart + replaceChar + lastPart;"));
my_file.println(F("        return newString;"));
my_file.println(F("    }"));
my_file.println(F(""));
my_file.println(F("    function add_step(){"));
my_file.println(F("        var count = document.getElementById('step_inputs').children.length;                                                                                      "));
my_file.println(F(""));
my_file.println(F("        if (count <= 20){                                                                                                                                                                            "));
my_file.println(F("            var original = document.getElementById('step_0');                                                                                       "));
my_file.println(F("            var clone = original.cloneNode(true);"));
my_file.println(F("            clone.id = '';"));
my_file.println(F("            original.parentNode.appendChild(clone);                                                                                                                    "));
my_file.println(F(""));
my_file.println(F("            for (var i = 0; i < 8; i++){                                                                                                        "));
my_file.println(F("                clone.children[i].children[0].checked = false;"));
my_file.println(F("            }"));
my_file.println(F("            for (var i = 0; i < 10; i++){                                                                                                            "));
my_file.println(F("                clone.children[i+8].children[0].value = '0';"));
my_file.println(F("            }"));
my_file.println(F(""));
my_file.println(F("            var original_data = document.getElementById('form_data');                                                                             "));
my_file.println(F("            var clone_data = original_data.cloneNode(true);"));
my_file.println(F("            clone.id = '';"));
my_file.println(F("            clone_data.setAttribute('name','step_' + (count - 1) + '_data');"));
my_file.println(F(""));
my_file.println(F("            clone_data.value = '00000000000000000000000000000000000000';                                                                  "));
my_file.println(F(""));
my_file.println(F("            original_data.parentNode.appendChild(clone_data);                                                                                        "));
my_file.println(F("        }"));
my_file.println(F("    }"));
my_file.println(F(""));
my_file.println(F("    function remove_step(){"));
my_file.println(F("        var count = document.getElementById('step_inputs').children.length;                                                                                      "));
my_file.println(F(""));
my_file.println(F("        if (count > 2){                                                                                                                                    "));
my_file.println(F("            let input = document.getElementById('step_inputs');                                                                     "));
my_file.println(F("            input.removeChild(input.lastChild);"));
my_file.println(F(""));
my_file.println(F("            let data = document.getElementById('my_form');                                                                             "));
my_file.println(F("            data.removeChild(data.lastChild);   "));
my_file.println(F("        }"));
my_file.println(F("    }"));
my_file.println(F(""));
my_file.println(F("    function update_program_number(){"));
my_file.println(F("        var program_number = document.getElementById('program_ui').value;"));
my_file.println(F("        document.getElementById('program').value = program_number;"));
my_file.println(F("    }"));
my_file.println(F("</script>"));
my_file.println(F("</body>"));
my_file.println(F("</html>"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html.txt file on SD card");
}


void loop() {
 
}
