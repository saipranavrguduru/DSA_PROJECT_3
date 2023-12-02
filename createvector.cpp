#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main2() {
    vector<vector<string>> contents;

    ifstream file;
    file.open("smoking.csv");
    string line;
    string temp;
    if(file.is_open()){ //open file
        while(getline(file, line)){
            vector<string> lineContent;
            line = line + ','; //make sure last value is read
            for(int i = 0; i < line.length(); i++){
                if (line[i] != ',')
                    temp += line[i];
                else{
                    lineContent.push_back(temp); //adding data before each comma
                    temp = "";
                }
            }
            contents.push_back(lineContent); //adding row of data
        }
    }
    /*for(int i = 0; i < 6205; i++){
        for(int j = 0; j < 9; j++){
            cout << contents[i][j] << " ";
        }
        cout << endl;
    }*/
}