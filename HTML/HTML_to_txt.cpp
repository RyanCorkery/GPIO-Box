#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream my_file;
    ofstream new_file;

    vector<string> html_data;

    my_file.open("html.txt", ios::in);

    if (my_file){
        cout << "html.txt file opened" << '\n';
        string line;
        while (getline(my_file, line)){
            html_data.push_back(line);
        }
    }
    else{
        cout << "html.txt file failed to open";
        return 0;
    }

    string prefix = "my_file.println(\"";
    string sufix = "\");";
    new_file.open("html_Arduino.txt", ios::out);

    if (new_file){
        cout << "new_file opened";
        int i_index = 0;
        for (auto i : html_data){
            int n_index = 0;
            for (auto n : i){
                if (n == '\"') {
                    html_data[i_index][n_index] = '\'';
                }
                n_index++;
            }
            new_file << prefix << html_data[i_index] << sufix << endl;
            i_index++;
        }
    }
    else{
        cout << "html_Arduino failed to open" << endl;
        if (my_file) my_file.close();                                       // Close my_file
        return 0;
    }

    my_file.close();
    new_file.close();

    return 0;
}