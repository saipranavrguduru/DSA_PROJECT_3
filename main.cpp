#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main2(std::vector<std::vector<std::string>>& contents) {
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



void InsertionSort(vector<vector<string>>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        vector<string> key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(vector<vector<string>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void BubbleSort(){
    cout << 0;
}
void HeapSort(){
    cout << 0;
}
void QuickSort(){
    cout << 0;
}
void IntroSort(){
    cout << 0;
}
void IntroductionText(){
    cout << "What would you like to learn about this algorithm?" << endl;
    cout << "1. History of Algorithm!" << endl;
    cout << "2. Time Complexity" << endl;
}
int main() {
    cout << "Welcome to Our Project 3!!!" << endl;
    cout << "Choose Between these Algorithms so you can learn about them!!" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Heap Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Intro Sort" << endl;
    vector<vector<string>> contents;
    main2(contents);
    int Input;
    cin >> Input;
    // takes in an input


    if (Input == 1) {
        //this introduction text function displays an introduction and gives a bunch of options.
        IntroductionText();
        int input1choice;
        cin >> input1choice;
        if (input1choice == 1) {
            std::cout << "Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons "
                      << "\nBest case time complexity of Insertion Sort is O(n) with worst and average case being O(n^2)"
                    << "\nIt’s first use in a computation context traces back to 1945 when Konrad Zuse defined it as a primitive for the first high-level programming language."
                    << "\nSource: https://en.wikipedia.org/wiki/Insertion_sort"
                      << "\nSource: https://hideoushumpbackfreak.com/algorithms/sorting-insertion.html#:~:text=The%20origin%20of%20insertion%20sort,%2Dlevel%20programming%20language%3A%20Plankalkül." << std::endl;
        }
        if (input1choice == 2) {
            InsertionSort(contents);
        }


        else if (Input == 2)
            IntroductionText();
            int input2choice;
            cin >> input2choice;
        if (input2choice == 1) {
            std::cout << "Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited."
                      << "\nIt has an O(n2) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort."
                      << "\nSelection sort can be used on list structures that make add and remove efficient, such as a linked list."
                      << "\nSource: https://en.wikipedia.org/wiki/Selection_sort" << std::endl;
        }
        if (input2choice == 2) {
            SelectionSort(contents);
        }




        else if (Input == 3)
            BubbleSort();
        else if (Input == 4)
            HeapSort();
        else if (Input == 5)
            QuickSort();
        else if (Input == 6)
            IntroSort();
        return 0;
    }



// insertion sort
// selection sort
}