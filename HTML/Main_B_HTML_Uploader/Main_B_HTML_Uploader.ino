#include <SPI.h>
#include <SD.h>

File my_file;

void setup() {
  Serial.begin(9600);

  if (!SD.begin(4)) {                                                             // Initialize SD card
    Serial.println("SD failed");
    while (1);
  }

  SD.remove("htmlB.txt");

  my_file = SD.open("htmlB.txt", FILE_WRITE);

  if (my_file){
    Serial.println("htmlB.txt opened successfully");
    // ******************************** //
    // Copy and past html_Arduino below
    // ******************************** //
my_file.println(F("'>"));
my_file.println(F("<form id='delete_form' method='post' action='/'>"));
my_file.println(F("    <input type='text' id='program_number_delete' value='' name='delete' hidden>"));
my_file.println(F("</form>"));
my_file.println(F(""));
my_file.println(F("<script>"));
my_file.println(F("    function save_data(){"));

my_file.println(F("var program_number = document.getElementById('program_ui').value;"));
my_file.println(F("        var file_list = document.getElementById('program_list').value;"));
my_file.println(F("        if (program_number.length == 1) program_number = '0' + program_number;"));
my_file.println(F("        if (document.getElementById('program_list').value.includes(program_number)){"));
my_file.println(F("            if (program_number == '00') alert('Program 0 can not be modified');"));
my_file.println(F("            else alert('Program ' + program_number + ' exists. Overwrite? Make selection on IO box. Click ok to proceed');"));
my_file.println(F("        }"));
my_file.println(F("       else{"));
my_file.println(F("           var file_list = file_list.concat(program_number, '-');"));
my_file.println(F("           document.getElementById('program_list').value = file_list;"));
my_file.println(F("}"));

my_file.println(F("        var number_of_steps = document.getElementById('step_inputs').children.length - 1;                                                              "));
my_file.println(F(""));
my_file.println(F("        var inputs = document.getElementById('step_inputs');                                                                                                                                  "));
my_file.println(F("        inputs = inputs.getElementsByTagName('input');"));
my_file.println(F("        var value;                                                                                                                                          "));
my_file.println(F(""));
my_file.println(F("        for (var x = 0; x < number_of_steps; x++){                                                                                                                                 '       '                       "));
my_file.println(F("            var current_data = '00000000000000000000000000000000000000';"));
my_file.println(F("            for (var i = 0; i < 8; i++) {                                                                                                                        "));
my_file.println(F("                if (inputs[i+x*18].type === 'checkbox') {"));
my_file.println(F("                    if (inputs[i+x*18].checked){                                                                                                               "));
my_file.println(F("                        value = inputs[i+x*18].value;    "));
my_file.println(F("                        current_data = replaceChar(current_data, '1', i);"));
my_file.println(F("                    }   "));
my_file.println(F("                }"));
my_file.println(F("            }"));
my_file.println(F("            for (var i = 0; i < 10; i++) {                                                                                                                                  "));
my_file.println(F("                if (inputs[i+x*18+8].type === 'number') {"));
my_file.println(F("                    value = inputs[i+x*18+8].value;                                                                                       "));
my_file.println(F("                    value = map_value(value);"));
my_file.println(F("                    "));
my_file.println(F("                    for (var n = 2; n>=0; n--){                                                                                                           "));
my_file.println(F("                        if (value[n]){                                                                                                                         "));
my_file.println(F("                            current_data = replaceChar(current_data, value[n], i*3+8+n);"));
my_file.println(F("                        }"));
my_file.println(F("                    }"));
my_file.println(F("                }"));
my_file.println(F("            }"));
my_file.println(F("            document.getElementById('my_form').children[x+6].value = current_data;"));
my_file.println(F("        }"));

my_file.println(F("        var description = document.getElementById('description');"));
my_file.println(F("        if (description.value == '') description.value = ' ';"));

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
my_file.println(F("            var original = document.getElementById('step_inputs').children[1];                                                                                       "));
my_file.println(F("            var clone = original.cloneNode(true);"));
my_file.println(F("            clone.id = count - 1;"));
my_file.println(F("            original.parentNode.appendChild(clone);                                                                                                                    "));
my_file.println(F(""));
my_file.println(F("            for (var i = 0; i < 8; i++){                                                                                                        "));
my_file.println(F("                clone.children[i+1].children[0].checked = false;                                                                            "));
my_file.println(F("            }"));
my_file.println(F("            for (var i = 0; i < 10; i++){                                                                                                            "));
my_file.println(F("                clone.children[i+1+8].children[0].value = '0';                                                                              "));
my_file.println(F("            }"));
my_file.println(F(""));
my_file.println(F("            var original_data = document.getElementById('form_data');                                                                             "));
my_file.println(F("            var clone_data = original_data.cloneNode(true);"));
my_file.println(F("                          '' "));
my_file.println(F("            clone_data.setAttribute('name','step_' + (count - 1) + '_data');"));
my_file.println(F(""));
my_file.println(F("            clone_data.value = '00000000000000000000000000000000000000';                                                                  "));
my_file.println(F(""));
my_file.println(F("            original_data.parentNode.appendChild(clone_data);                                                                                        "));
my_file.println(F("        "));
my_file.println(F("            document.getElementById(clone.id).children[0].textContent = clone.id;"));
my_file.println(F("        }"));
my_file.println(F("    }"));
my_file.println(F(""));
my_file.println(F("    function remove_step(){"));
my_file.println(F("        var count = document.getElementById('step_inputs').children.length;                                                                                      "));
my_file.println(F(""));
my_file.println(F("        if (count > 2){                                                                                                                                    "));
my_file.println(F("            var input = document.getElementById('step_inputs');                                                                     "));
my_file.println(F("            input.removeChild(input.lastChild);"));
my_file.println(F("            input.removeChild(input.lastElementChild);"));
my_file.println(F(""));
my_file.println(F("            let data = document.getElementById('my_form');                                                                             "));
my_file.println(F("            data.removeChild(data.lastChild);   "));
my_file.println(F("        }"));
my_file.println(F("    }"));
my_file.println(F(""));
my_file.println(F("    function update_program_number(selectObject){"));
my_file.println(F("       limit_input(selectObject, 2);"));
my_file.println(F("        var program_number = document.getElementById('program_ui').value;"));
my_file.println(F("        if (program_number == '') return;"));
my_file.println(F("        var raw_program_number = program_number;"));
my_file.println(F("        document.getElementById('program').value = program_number;"));
my_file.println(F("        document.getElementById('program_submit').value = program_number;"));
my_file.println(F("        document.getElementById('program_number_delete').value = program_number;"));
my_file.println(F("if (program_number.length == 1) program_number = '0' + program_number + '-';"));
my_file.println(F("else program_number = program_number + '-';"));
my_file.println(F("        if (document.getElementById('program_list').value.includes(program_number)){"));
my_file.println(F("            if (confirm('Load program ' + raw_program_number + '? Current data inputs will be lost')){"));
my_file.println(F("                document.getElementById('program_load').submit();"));
my_file.println(F("            }"));
my_file.println(F("        }"));
my_file.println(F("    }"));

my_file.println(F(""));
my_file.println(F("    function update_program_speed(selectObject){"));
my_file.println(F("       limit_input(selectObject, 4);"));
my_file.println(F("        var program_speed = document.getElementById('speed_ui').value;"));
my_file.println(F("        document.getElementById('speed').value = program_speed;"));
my_file.println(F("    }"));
my_file.println(F(""));


my_file.println(F("    function delete_program(){"));
my_file.println(F("        var program_number = document.getElementById('program_ui').value;"));
my_file.println(F("        var raw_program_number = program_number;"));
my_file.println(F("        var file_list = document.getElementById('program_list').value;"));
my_file.println(F("document.getElementById('program_number_delete').value = program_number;"));
my_file.println(F("if (program_number.length == 1) program_number = '0' + program_number + '-';"));
my_file.println(F("else program_number = program_number + '-';"));
my_file.println(F("        if (document.getElementById('program_list').value.includes(program_number)){"));
my_file.println(F("            if (confirm('Delete program ' + raw_program_number + '?')){"));
my_file.println(F("                document.getElementById('delete_form').submit();"));
my_file.println(F("                var file_list = file_list.replace(program_number, '');"));
my_file.println(F("                document.getElementById('program_list').value = file_list;"));
my_file.println(F("            }"));
my_file.println(F("        }"));
my_file.println(F("    }"));

my_file.println(F("window.addEventListener('load', page_load());"));
my_file.println(F("function page_load(){"));
my_file.println(F("document.getElementById('page_name').style.visibility = 'visible';"));
my_file.println(F("}"));

my_file.println(F("function limit_break(selectObject){"));
my_file.println(F("        let max_length = 3;"));
my_file.println(F("        var val = selectObject.value;"));
my_file.println(F("        if (String(val).length > max_length - 1) {"));
my_file.println(F("            selectObject.value = parseFloat(selectObject.value).toFixed(max_length-2);"));
my_file.println(F("        }"));
my_file.println(F("        if (val < 4) selectObject.value = 0;"));
my_file.println(F("        else if (val > 20) selectObject.value = 20;"));
my_file.println(F("    }"));

my_file.println(F("function limit_input(selectObject, max_length){"));
my_file.println(F("        selectObject.value = parseFloat(selectObject.value).toFixed(0);"));
my_file.println(F("        var val = selectObject.value;"));
my_file.println(F("        if (String(val).length > max_length) {"));
my_file.println(F("            var x;"));
my_file.println(F("            if (max_length == 2) x = 100;"));
my_file.println(F("            else if (max_length == 4) x = '10 000';"));
my_file.println(F("            alert('Enter a number less than ' + x);"));
my_file.println(F("            selectObject.value = '';"));
my_file.println(F("        }"));
my_file.println(F("        else if (val <= 0 && max_length == 4){"));
my_file.println(F("            alert('Enter a speed greater than 0');"));
my_file.println(F("            selectObject.value = '';"));
my_file.println(F("        }"));
my_file.println(F("        else if (val < 0 && max_length == 2){"));
my_file.println(F("            alert('Enter program number between 0 - 99');"));
my_file.println(F("            selectObject.value = '';"));
my_file.println(F("        }"));
my_file.println(F("    }"));

//my_file.println(F(" function map_value(x, in_min, in_max, out_min, out_max){"));
my_file.println(F(" function map_value(x){"));
my_file.println(F("         let in_min = 4;"));
my_file.println(F("         let in_max = 20;"));
my_file.println(F("         let out_min = 41;"));
my_file.println(F("         let out_max = 242;"));
my_file.println(F("         if (x < 4) return '000';"));
my_file.println(F("         else if (x == 4) return '041';"));
my_file.println(F("         var val_map = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;"));
my_file.println(F("         val_map = val_map.toFixed(0);"));
my_file.println(F("         val_map = String(val_map);"));
my_file.println(F("         var val = '';"));
my_file.println(F("         if (val_map.length == 3) val = val_map;"));
my_file.println(F("         else if (val_map.length == 2){"));
my_file.println(F("             val = val.concat('0');"));
my_file.println(F("             val = val.concat(val_map[0]);"));
my_file.println(F("             val = val.concat(val_map[1]);"));
my_file.println(F("         }"));
my_file.println(F("         else if (val_map.length == 1){"));
my_file.println(F("             val = val.concat('0');"));
my_file.println(F("             val = val.concat('0');"));
my_file.println(F("             val = val.concat(val_map[0]);"));
my_file.println(F("         }"));
my_file.println(F("         return val;"));
my_file.println(F("     }"));

my_file.println(F("</script>"));
my_file.println(F("</body>"));
my_file.println(F("</html>"));
    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open htmlB.txt file on SD card");
}


void loop() {
 
}
