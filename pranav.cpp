
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>Data;


void InsertionSort(){
    cout << 0;
}
void TestTwo(){
    cout << 0;
}
void TestThree(){
    cout << 0;
}
void TestFour(){
    cout << 0;
}
void TestFive(){
    cout << 0;
}
int main()
{
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
    // takes in an inpiut
    if (Input == 1)
        cout << "What would you like to learn about this algorithm?" << endl;
        cout << "1. History of Alogrithm!" << endl;
        cout << "2. Time Complexity" << endl;
        int input1choice;
        cin >> input1choice;
        if (input1choice == 1){
            cout << "will add this";
        }
        if (input1choice == 2){
            InsertionSort();
        }



    else if (Input == 2)
        TestTwo();
    else if (Input == 3)
        TestThree();
    else if (Input == 4)
        TestFour();
    else if (Input == 5)
        TestFive();
    else if (Input == 6)
        TestFive();
    return 0;
}



// insertion sort
// selection sort
