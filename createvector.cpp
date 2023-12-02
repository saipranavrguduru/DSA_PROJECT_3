#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main2() {
    ifstream file;
    file.open("smoking.csv");
    vector<vector<string>> contents;
    string line;
    string temp;
    if(file.is_open()){
        int k = 0;
        int j = 0;
        while(getline(file, line)){
            vector<string> lineContent;
            j = 0;
            line = line + ',';
            for(int i = 0; i < line.length(); i++){
                if (line[i] != ',')
                    temp += line[i];
                else{
                    lineContent.push_back(temp);
                    temp = "";
                    j++;
                }
            }
            contents.push_back(lineContent);
            k++;
        }
    }
    /*for(int i = 0; i < 6205; i++){
        for(int j = 0; j < 9; j++){
            cout << contents[i][j] << " ";
        }
        cout << endl;
    }*/
}