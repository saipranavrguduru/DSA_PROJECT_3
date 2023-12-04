#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <sstream>
using namespace std;
using namespace chrono;
// this prints the contents of the vector
void printVec(vector<vector<string>>& contents) {
    for(int i = 0; i < contents.size(); i++) {
        for (int j = 0; j < contents[i].size(); j++) {
            cout << contents[i][j] << " ";
        }
        cout << endl;
    }
}
// this creates a vector that we will use for sorting
int createVec(std::vector<std::vector<std::string>>& contents) {
    ifstream file("smoking.csv");
    string line;
    string temp;

    if(!file.is_open()){
        cout << "file not open" << "\n";
        return 0;
    }
    if(true){ //open file
        //cout << "hello" << "\n";
        while(getline(file, line)){
            vector<string> lineContent;
            // cout << "line: " << line << "\n";
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
    file.close();
}
// helper function for insertion sort
void insertSortHelper(vector<string> &arr){
    for (int i = 2; i < arr.size(); i++){
        int j = i-1;
        float val = stof(arr[i]);
        while(j >= 1 && val < stof(arr[j])){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = to_string(val);
    }
    for(string val : arr)
        cout << val << "\n";
}
// insertion sort function. it takes in an input of row, so if u choose -1 it sorts all the rows.
void InsertionSort(vector<vector<string>>& arr, int r) {
    cout << "size: " << arr.size() << "\n";
    if(r == -1) {
        for(int r = 1; r < arr.size();r++){
            insertSortHelper(arr[r]);}
    }
    else {
        for(int r = 1; r < 1000;r++){
            insertSortHelper(arr[r]);
    }
    }
}
// this is a helper function for selection sort
void selectionsorthelper(vector<string> &arr){
    for(int i = 1; i < arr.size();i++){
        int minIdx = i;
        for(int j = i;j < arr.size();j++){
            if(stof(arr[j]) < stof(arr[minIdx])){
                minIdx = j;}
        }
        swap(arr[i],arr[minIdx]);
    }
    for(string val : arr)
        cout << val << "\n";
}
// selection sort function and it takes an input of r too which lets it decide if it wants to sort one row or all the rows
void SelectionSort(vector<vector<string>>& arr, int r) {
    cout << "size: " << arr.size() << "\n";
    if(r == -1 ) {
        for(int r = 1; r < arr.size();r++){
            selectionsorthelper(arr[r]);}
    }
    else {
        for(int r = 1; r < 1000;r++){
            selectionsorthelper(arr[r]);}
    }
}





void BubbleSortHelper(vector<string> &arr){
    for (int i = 1; i < arr.size(); i++){
        for (int j = 1; j < arr.size() - i; j++){
            if (stof(arr[j]) > stof(arr[j+1]))
                swap(arr[j], arr[j+1]);
        }
    }
    for(string val : arr)
        cout << val << "\n";
}
void BubbleSort(vector<vector<string>>& arr , int r) {
    cout << "size: " << arr.size() << "\n";
    if (r == -1) {
        for (int r = 1; r < arr.size(); r++) {
            BubbleSortHelper(arr[r]);
        }
    } else {
        for (int r = 1; r < 1000; r++) {
            BubbleSortHelper(arr[r]);
        }
    }
}



void heaptifyDown(vector<string>& arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && stof(arr[l]) > stof(arr[largest]))
        largest = l;
    if (r < n && stof(arr[r]) > stof(arr[largest]))
        largest = r;
    if (largest != i){
        swap(arr[i], arr[largest]);
        heaptifyDown(arr, n, largest);
    }
}
void HeapSort(vector<string>& arr){
    int n = arr.size();
    for (int i = (n/2) - 1; i >= 1; i--){
        heaptifyDown(arr, n, i);
    }
    for (int i = n - 1; i >= 1; i--){
        swap(arr[0], arr[i]);
        heaptifyDown(arr, i, 0);
    }
    for(string val : arr)
        cout << val << "\n";
}

void IntroductionText(){
    cout << "What would you like to learn about this algorithm?" << endl;
    cout << "1. History of Algorithm!" << endl;
    cout << "2. Time Complexity" << endl;
}
void RowSelect(){
    cout << "How many rows do you want to sort?" << endl;
    cout << "1. 1000 Rows" << endl;
    cout << "2. All Rows" << endl;
}
int main() {
    // this is the initial entry text
    cout << "Welcome to Our Project 3!!!" << endl;
    cout << "Choose Between these Algorithms so you can learn about them!!" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Heap Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Merge Sort" << endl;
    // instantiating a 2dvector
    vector<vector<string>> contents;
    createVec(contents);
    int Input;
    cin >> Input;
    // takes in an input
    // insertion sort
    if (Input == 1) {
        //this introduction text function displays an introduction and gives a bunch of options.
        IntroductionText();
        int input1choice;
        cin >> input1choice;
        if (input1choice == 1) {
            std::cout
                    << "Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons "
                    << "\nBest case time complexity of Insertion Sort is O(n) with worst and average case being O(n^2)"
                    << "\nIt’s first use in a computation context traces back to 1945 when Konrad Zuse defined it as a primitive for the first high-level programming language."
                    << "\nSource: https://en.wikipedia.org/wiki/Insertion_sort"
                    << "\nSource: https://hideoushumpbackfreak.com/algorithms/sorting-insertion.html#:~:text=The%20origin%20of%20insertion%20sort,%2Dlevel%20programming%20language%3A%20Plankalkül."
                    << std::endl;


        } else if (input1choice == 2) {
            // this gives u a selection of if u want to do one row or all the rows
            RowSelect();
            int row;
            cin >> row;
            if (row == 1){
                // this will sort it with 1 row
                auto start_time = chrono::high_resolution_clock::now();
                InsertionSort(contents, 1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took:" << duration.count() << " amount of milliseconds to run this sorting algorithm on 1000 rows";
            }
            else{
                // this will sort all the rows
                auto start_time = chrono::high_resolution_clock::now();
                InsertionSort(contents, -1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took:" << duration.count() << " amount of milliseconds to run this sorting algorithm";
            }
        }
    }


    // selection sort
    else if (Input == 2) {
        IntroductionText();
        int input2choice;
        cin >> input2choice;
        if (input2choice == 1) {
            std::cout
                    << "Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited."
                    << "\nIt has an O(n^2) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort."
                    << "\nSelection sort can be used on list structures that make add and remove efficient, such as a linked list."
                    << "\nSource: https://en.wikipedia.org/wiki/Selection_sort" << std::endl;
        } else if (input2choice == 2) {
            // u select a row here
            RowSelect();
            int row;
            cin >> row;
            if (row == 1) {
                // this is if u want to sort 1 row
                auto start_time = chrono::high_resolution_clock::now();
                SelectionSort(contents, 1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took:" << duration.count() << " amount of milliseconds to run this sorting algorithm on 1000 rows";
            }
            else{
                // this is for all the rows
                auto start_time = chrono::high_resolution_clock::now();
                SelectionSort(contents, -1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took:" << duration.count() << " amount of milliseconds to run this sorting algorithm";
            }
        }
    }


// bubble sort

    else if (Input == 3){
        IntroductionText();
        int input2choice;
        cin >> input2choice;
        if (input2choice == 1) {
            std::cout
                    << "Bubble sort is a simple sorting algorithm commonly used for quick sorting of smaller data sets. It treats its data like bubbles repeatedly swapping and with larger elements that bubble up to the top."
                    << "\nIt has an O(n^2) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort."
                    << "\nSelection sort can be used on list structures that make add and remove efficient, such as a linked list."
                    << "\nSource: https://en.wikipedia.org/wiki/Bubble_sort" << std::endl;
        }
        else if (input2choice == 2) {
            RowSelect();
            int row;
            cin >> row;
            if (row == 1) {
                auto start_time = chrono::high_resolution_clock::now();
                BubbleSort(contents, 1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " amount of milliseconds to run this sorting algorithm on 1000 rows";
            }
            else{
                auto start_time = chrono::high_resolution_clock::now();
                BubbleSort(contents, -1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " amount of milliseconds to run this sorting algorithm";
            }
        }
    }



// heap sort

    else if (Input == 4){
        IntroductionText();
        int input2choice;
        cin >> input2choice;
        if (input2choice == 1) {
            std::cout
                    << "Heap sort algorithm is a combination of building a MIN heap in place and then extracting each value from the heap into vector/array."
                    << "\nIt has an O(nlogn) time complexity, which makes it an efficient sorting algorithm and has a O(1) space complexity which is more efficient than algorithms like merge sort."
                    << "\nHeap sort is usually used when the smallest or highest value is needed instantly or dealing with priority queues like Prim's algorithm and Huffman encoding"
                    << "\nSource: https://www.upgrad.com/blog/heap-sort-in-data-structures" << std::endl;
        }
        else if (input2choice == 2) {
            RowSelect();
            int row;
            cin >> row;
            if (row == 1) {
                auto start_time = chrono::high_resolution_clock::now();
                for (int r = 1; r < 1000; r++) {
                    HeapSort(contents[r]);
                }
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " amount of milliseconds to run this sorting algorithm on 1000 rows";
            }
            else{
                auto start_time = chrono::high_resolution_clock::now();
                for (int r = 1; r < contents.size(); r++) {
                    HeapSort(contents[r]);
                }
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " amount of milliseconds to run this sorting algorithm";
            }
        }
    }




    return 0;
}
