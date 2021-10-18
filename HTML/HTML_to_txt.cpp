// Append text to each line of html.txt
// html_arduino.txt is used in HTML_Uplaoder.ino


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream my_file;
    ofstream new_file;

    vector<string> html_data;                                                                 // Vector stores html data

    my_file.open("html.txt", ios::in);                                                        // Open html.txt

    if (my_file){
        cout << "html.txt file opened" << '\n';
        string line;
        while (getline(my_file, line)){                                                       // Read html.txt line by line
            html_data.push_back(line);                                                        // Append each line to html vector
        }
    }
    else{
        cout << "html.txt file failed to open";
        return 0;
    }

    string prefix = "my_file.println(F(\"";
    string sufix = "\"));";
    new_file.open("html_Arduino.txt", ios::out | ios::trunc);                                 // Open html_arduino.txt

    if (new_file){
        cout << "new_file opened";
        int i_index = 0;
        bool slash = false;

        for (auto i : html_data){                                                             // Loop through each line in html.txt
            int n_index = 0;
            for (auto n : i){                                                                 // Loop through each char in each line of html.txt
                if (n == '\"') {
                    html_data[i_index][n_index] = '\'';                                       // Replace all double quotes with single quotes. HTML_Uploader can't have double quotes
                }
                if (n == '/' && slash){                                                       // Remove comments from html file
                    for (int x = n_index; x <= html_data[i_index].length(); x++){
                        html_data[i_index][x] = ' '; 
                        if (x == n_index) html_data[i_index][x-1] = ' '; 
                    }
                    slash = false;
                }
                else if (n == '/') slash = true;
                else if (slash = true) slash = false;
                n_index++;
            }
            new_file << prefix << html_data[i_index] << sufix << endl;                        // Append prefix and sufix
            i_index++;
        }
    }
    else{
        cout << "html_Arduino failed to open" << endl;
        if (my_file) my_file.close();                                                         // Close html.txt
        return 0;
    }

    my_file.close();
    new_file.close();

    return 0;
}