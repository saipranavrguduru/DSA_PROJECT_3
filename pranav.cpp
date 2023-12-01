
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>Data;


void InsertionSort(){

    cout << 0;
}
void SelectionSort(){
    cout << 0;
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
    cout << "1. History of Alogrithm!" << endl;
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

    int Input;
    cin >> Input;
    // takes in an input
    if (Input == 1) {
        //this introduction text function displays an introduction and gives a bunch of options.
        IntroductionText();
        int input1choice;
        cin >> input1choice;

        if (input1choice == 1) {
            cout << "will add this";
        }
        if (input1choice == 2) {
            InsertionSort();
        } else if (Input == 2)
            SelectionSort();
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