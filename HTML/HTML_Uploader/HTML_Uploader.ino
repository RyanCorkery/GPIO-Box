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
   my_file.println("<html>");
my_file.println("");
my_file.println("<head>");
my_file.println("<meta http-equiv='Content-Language' content='nl'>");
my_file.println("<meta http-equiv='Content-Type' content='text/html; charset=windows-1252'>");
my_file.println("<title>GPIO Box REV 2</title>");
my_file.println("<style>");
my_file.println("h1 {");
my_file.println("    text-align: center;");
my_file.println("}");
my_file.println("</style>");
my_file.println("</head>");
my_file.println("");
my_file.println("");
my_file.println("<body>");
my_file.println("");
my_file.println("<h1>GPIO Box REV 2</h1>");
my_file.println("");
my_file.println("Program Number: <input><br><br>");
my_file.println("");
my_file.println("<!-- Brake 1 <input type='checkbox'><br>");
my_file.println("Brake 2 <input type='checkbox'><br>");
my_file.println("Brake 3 <input type='checkbox'><br> -->");
my_file.println("");
my_file.println("<!-- <button onclick='save_data()'>Save Program</button>  -->");
my_file.println("");
my_file.println("<!-- <div id='arduino_data'>");
my_file.println("    <div id='new_data'>0</div>");
my_file.println("    <div>01</div>");
my_file.println("    <div>1234</div>");
my_file.println("    <div id='div2'>60000000000000000000000000000000000000</div>");
my_file.println("    <div>00000000000000000000000000000000000000</div>");
my_file.println("    <div>00000000000000000000000000000000000000</div>");
my_file.println("    <div>00000000000000000000000000000000000000</div>");
my_file.println("</div> -->");
my_file.println("");
my_file.println("<form method='post' action='/' name='pins' onsubmit='save_data()'>");
my_file.println("    Brake 1 <input type='checkbox' name='B1'><br>");
my_file.println("    Brake 2 <input type='checkbox' name='B2'><br>");
my_file.println("    Brake 3 <input type='checkbox' name='B3'><br>");
my_file.println("    <input type='text' name='step_1' value='00000000000000000000000000000000000000'><br>");
my_file.println("    <input type='submit' value='Save program'>");
my_file.println("</form>");
my_file.println("");
my_file.println("");
my_file.println("");
my_file.println("");
my_file.println("");
my_file.println("<script>");
my_file.println("    function save_data(){");
my_file.println("        var checkboxes = document.getElementsByTagName('input');");
my_file.println("        var value;");
my_file.println("        for (var i = 0; i < checkboxes.length; i++) {");
my_file.println("            if (checkboxes[i].type === 'checkbox') {");
my_file.println("                if (checkboxes[i].checked){");
my_file.println("                    value = checkboxes[i].value;    ");
my_file.println("                    var original = document.getElementById('step_1').value;");
my_file.println("                    var new_string = replaceChar(original, '1', i);");
my_file.println("                    document.getElementById('step_1').value = new_string;");
my_file.println("                }   ");
my_file.println("            }");
my_file.println("        }");
my_file.println("        // document.getElementById('new_data').innerHTML = '1';");
my_file.println("    }");
my_file.println("");
my_file.println("    function replaceChar(origString, replaceChar, index) {");
my_file.println("        let firstPart = origString.substr(0, index);");
my_file.println("        let lastPart = origString.substr(index + 1);");
my_file.println("        ");
my_file.println("        let newString = firstPart + replaceChar + lastPart;");
my_file.println("        return newString;");
my_file.println("    }");
my_file.println("</script>");
my_file.println("</body>");
my_file.println("</html>");

    // ******************************** //
    // End copy and paste
    // ******************************** //
  
    my_file.close();
  }
  else Serial.println("Failed to open html.txt file on SD card");
}


void loop() {
 
}
