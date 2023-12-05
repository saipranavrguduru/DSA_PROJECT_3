#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

//Function to create a 2D vector from dataset
vector<vector<string>> createVec() {
    //Initializing Variables
    vector<vector<string>> contents;
    ifstream file("smoking.csv");
    string line;
    string temp;

    //Adding Data to 2D Vector
    if (file.is_open()) {
        while (getline(file, line)){
            vector<string> lineContent;
            line = line + ','; //make sure last value is read

            for (int i = 0; i < line.length(); i++){
                if (line[i] != ',')
                    temp += line[i];
                else {
                    lineContent.push_back(temp);
                    temp = "";
                }
            }
            contents.push_back(lineContent);
        }
    }

    //Deleting First Row of Vector (as it's titles for the columns)
    contents[0].clear();
    contents.erase(contents.begin());


    file.close();
    return contents;
}

//Insertion Sort Helper Function
void InsertSortHelper(vector<string> &arr){
    for (int i = 2; i < arr.size(); i++){
        int j = i-1;
        float val = stof(arr[i]);
        while (j >= 1 && val < stof(arr[j])){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = to_string(val);
    }
    for(string val : arr)
        cout << val << "\n";
}

// insertion Sort Function that takes an input of r determines if user wants to sort 1000 rows or all rows
void InsertionSort(vector<vector<string>>& arr, int r) {
    if (r == -1) {
        for(int i = 1; i < arr.size(); i++){
            InsertSortHelper(arr[i]);
        }
    }
    else {
        for (int i = 1; i < 1000; i++){
            InsertSortHelper(arr[i]);
        }
    }
}

// Selection Sort Helper Function
void SelectionSortHelper(vector<string> &arr){
    for (int i = 1; i < arr.size();i++){
        int minIdx = i;
        for (int j = i; j < arr.size(); j++){
            if(stof(arr[j]) < stof(arr[minIdx])){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
    for (string val : arr) {
        cout << val << "\n";
    }
}

//Selection Sort Function that takes an input of r determines if user wants to sort 1000 rows or all rows
void SelectionSort(vector<vector<string>>& arr, int r) {
    if (r == -1) {
        for (int i = 1; i < arr.size(); i++){
            SelectionSortHelper(arr[i]);
        }
    }
    else {
        for (int i = 1; i < 1000; i++){
            SelectionSortHelper(arr[i]);
        }
    }
}


//Bubble Sort Helper Function
void BubbleSortHelper(vector<string> &arr){
    for (int i = 1; i < arr.size(); i++){
        for (int j = 1; j < arr.size() - i; j++){
            if (stof(arr[j]) > stof(arr[j+1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for(string val : arr) {
        cout << val << "\n";
    }
}

//Bubble Sort Function that takes an input of r determines if user wants to sort 1000 rows or all rows
void BubbleSort(vector<vector<string>>& arr , int r) {
    if (r == -1) {
        for (int i = 1; i < arr.size(); i++) {
            BubbleSortHelper(arr[i]);
        }
    }
    else {
        for (int i = 1; i < 1000; i++) {
            BubbleSortHelper(arr[i]);
        }
    }
}

//HeapifyDown Function for Heap Sort
void heapifyDown(vector<string>& arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && stof(arr[l]) > stof(arr[largest])) {
        largest = l;
    }
    if (r < n && stof(arr[r]) > stof(arr[largest])) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

//Heap Sort Function
void HeapSort(vector<string>& arr){
    int n = arr.size();
    for (int i = (n/2) - 1; i >= 1; i--){
        heapifyDown(arr, n, i);
    }
    for (int i = n - 1; i >= 1; i--){
        swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
    for(string val : arr)
        cout << val << "\n";
}


//Partition Function for Quick Sort
int partition(vector<vector<string>> &data, int low, int high, int n) {
    //Picking first element of container as pivot
    float pivot = stod(data[low][n]);
    int up = low, down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (stof(data[up][n]) > pivot) {
                break;
            }
            up++;
        }

        for (int i = high; i > low; i--) {
            if (stof(data[down][n]) < pivot) {
                break;
            }
            down--;
        }

        if (up < down) {
            swap(data[up], data[down]);
        }

    }
    swap(data[low], data[down]);
    return down;
}

//Quick Sort Function that takes left, right, and column as input
void QuickSort(vector<vector<string>> &data, int low, int high, int n){
    if (low < high) {
        int pivot = partition(data, low, high, n);
        QuickSort(data, low, pivot - 1, n);
        QuickSort(data, pivot + 1, high, n);
    }
}


//Merge Function for Merge Sort
void merge(vector <vector<string>> &data, int left, int mid, int right, int n) {
    //Creating two sub-vectors from input vector
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector <vector<string>> leftVector(n1);
    vector <vector<string>> rightVector(n2);

    for (int i = 0; i < leftVector.size(); i++) {
        leftVector[i] = data[left + i];
    }
    for (int i = 0; i < rightVector.size(); i++) {
        rightVector[i] = data[mid + 1 + i];
    }

    //Variables to keep tack of index
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (stof(leftVector[i][n]) <= stof(rightVector[j][n])) {
            data[k] = leftVector[i];
            i++;
        }
        else {
            data[k] = rightVector[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = leftVector[i];
        i++;
        k++;
    }
    while (j < n2) {
        data[k] = rightVector[j];
        j++;
        k++;
    }
}

//Merge Sort Function that takes left, right, and column as input
void MergeSort(vector <vector <string>> &data, int left, int right, int n){
    if (left < right) {
        //Variable picking middle of container
        int mid = left + (right - left) / 2;

        //Sort left side of container
        MergeSort(data, left, mid, n);

        //Sort right side of container
        MergeSort(data, mid + 1, right, n);

        //Merge two sorted arrays
        merge(data, left, mid, right, n);
    }
}

//Text Functions
void IntroductionText(){
    cout << "What would you like to learn about this algorithm?" << endl;
    cout << "1. History of Algorithm!" << endl;
    cout << "2. Time Complexity" << endl;
}
void RowSelect(){
    cout << "How many rows do you want to sort?" << endl;
    cout << "1. 1000 Row" << endl;
    cout << "2. All Rows" << endl;
}
void ColSelect(){
    cout << "Which columns do you want to sort?" << endl;
    cout << "1. 1 Column" << endl;
    cout << "2. All Columns" << endl;
}

int main() {
    //Initial Menu
    cout << "Welcome to Our Project 3!!!" << endl;
    cout << "Choose Between these Algorithms so you can learn about them!!" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Selection Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Heap Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Merge Sort" << endl;

    //Initializing 2D Vector that stores data
    vector<vector<string>> contents = createVec();

    //Taking in user input
    int Input;
    cin >> Input;

    //Insertion Sort
    if (Input == 1) {
        //Introduction text to see history or time complexity of chosen algorithm
        IntroductionText();
        int input1choice;
        cin >> input1choice;

        //History of the Algorithm
        if (input1choice == 1) {
            std::cout
                    << "Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time by comparisons "
                    << "\nBest case time complexity of Insertion Sort is O(n) with worst and average case being O(n^2)"
                    << "\nIt’s first use in a computation context traces back to 1945 when Konrad Zuse defined it as a primitive for the first high-level programming language."
                    << "\nSource: https://en.wikipedia.org/wiki/Insertion_sort"
                    << "\nSource: https://hideoushumpbackfreak.com/algorithms/sorting-insertion.html#:~:text=The%20origin%20of%20insertion%20sort,%2Dlevel%20programming%20language%3A%20Plankalkül."
                    << std::endl;
        }

            //Time Complexity
        else if (input1choice == 2) {
            //Text to choose to sort 1000 rows or all rows in dataset
            RowSelect();
            int row;
            cin >> row;
            //1000 rows
            if (row == 1){
                auto start_time = chrono::high_resolution_clock::now();
                    InsertionSort(contents, 1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm on 1000 rows.";
            }
                //All rows
            else {
                auto start_time = chrono::high_resolution_clock::now();
                InsertionSort(contents, -1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm.";
            }
        }
    }

        //Selection Sort
    else if (Input == 2) {
        //Introduction text to see history or time complexity of chosen algorithm
        IntroductionText();
        int input2choice;
        cin >> input2choice;

        //History of Algorithm
        if (input2choice == 1) {
            std::cout
                    << "Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited."
                    << "\nIt has an O(n^2) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort."
                    << "\nSelection sort can be used on list structures that make add and remove efficient, such as a linked list."
                    << "\nSource: https://en.wikipedia.org/wiki/Selection_sort" << std::endl;
        }

            //Time Complexity
        else if (input2choice == 2) {
            //Text to choose to sort 1000 rows or all rows in dataset
            RowSelect();
            int row;
            cin >> row;

            //100 rows
            if (row == 1) {
                auto start_time = chrono::high_resolution_clock::now();
                    SelectionSort(contents, 1);

                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm on 1000 rows.";
            }

                //All rows
            else {
                auto start_time = chrono::high_resolution_clock::now();
                SelectionSort(contents, -1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm.";
            }
        }
    }

        //Bubble Sort
    else if (Input == 3){
        //Introduction text to see history or time complexity of chosen algorithm
        IntroductionText();
        int input2choice;
        cin >> input2choice;

        //History of Algorithm
        if (input2choice == 1) {
            std::cout
                    << "Bubble sort is a simple sorting algorithm commonly used for quick sorting of smaller data sets. It treats its data like bubbles repeatedly swapping and with larger elements that bubble up to the top."
                    << "\nIt has an O(n^2) time complexity, which makes it inefficient on large lists, and generally performs worse than the similar insertion sort."
                    << "\nSelection sort can be used on list structures that make add and remove efficient, such as a linked list."
                    << "\nSource: https://en.wikipedia.org/wiki/Bubble_sort" << std::endl;
        }

            //Time Complexity
        else if (input2choice == 2) {
            //Text to choose to sort 1000 rows or all rows in dataset
            RowSelect();
            int row;
            cin >> row;

            //1000 rows
            if (row == 1) {
                auto start_time = chrono::high_resolution_clock::now();
                    BubbleSort(contents, 1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm on 1000 rows.";
            }

                //All rows
            else {
                auto start_time = chrono::high_resolution_clock::now();
                BubbleSort(contents, -1);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm.";
            }
        }
    }

        //Heap Sort
    else if (Input == 4){
        //Introduction text to see history or time complexity of chosen algorithm
        IntroductionText();
        int input2choice;
        cin >> input2choice;

        //History of Algorithm
        if (input2choice == 1) {
            std::cout
                    << "Heap sort algorithm is a combination of building a MIN heap in place and then extracting each value from the heap into vector/array."
                    << "\nIt has an O(n log n) time complexity, which makes it an efficient sorting algorithm and has a O(1) space complexity which is more efficient than algorithms like merge sort."
                    << "\nHeap sort is usually used when the smallest or highest value is needed instantly or dealing with priority queues like Prim's algorithm and Huffman encoding"
                    << "\nSource: https://www.upgrad.com/blog/heap-sort-in-data-structures" << std::endl;
        }

            //Time Complexity
        else if (input2choice == 2) {
            //Text to choose to sort 1000 rows or all rows in dataset
            RowSelect();
            int row;
            cin >> row;

            //1000 rows
            if (row == 1) {
                auto start_time = chrono::high_resolution_clock::now();
                    HeapSort(contents[1]);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm on 1000 rows.";
            }

                //All rows
            else {
                auto start_time = chrono::high_resolution_clock::now();
                for (int r = 1; r < contents.size(); r++) {
                    HeapSort(contents[r]);
                }
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm.";
            }
        }
    }

        //Quick Sort
    else if (Input == 5) {
        //Introduction text to see history or time complexity of chosen algorithm
        IntroductionText();
        int input1choice;
        cin >> input1choice;

        //History of Algorithm
        if (input1choice == 1) {
            std::cout
                    << "Quick Sort is a divide and conquer algorithm that selects a pivot and partitions the container around the pivot."
                    << "\nThe best and average case time complexity for quicksort is O(n log n). The worst case time complexity for quicksort is O(n^2). This comes a s a result of an inefficient pivot picking strategy."
                    << "\nQuicksort was first developed in 1959 by Tony Hoare and used in 1961."
                    << "\nSource: https://en.wikipedia.org/wiki/Quicksort"
                    << std::endl;
        }

            //Time Complexity
        else if (input1choice == 2) {
            //Text to choose to sort 1 column or all columns in dataset
            ColSelect();
            int col;
            cin >> col;

            //One column
            if (col == 1){
                auto start_time = chrono::high_resolution_clock::now();
                QuickSort(contents, 0, contents.size() - 1, 2);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm on 1 column.";
            }

                //All columns
            else {
                auto start_time = chrono::high_resolution_clock::now();
                for (int i = 2; i < 9; i++) {
                    QuickSort(contents, 0, contents.size() - 1, i);
                }
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " milliseconds to run this sorting algorithm.";
            }
        }
    }

        //Merge Sort
    else if (Input == 6) {
        //Introduction text to see history or time complexity of chosen algorithm
        IntroductionText();
        int input1choice;
        cin >> input1choice;

        //History of Algorithm
        if (input1choice == 1) {
            std::cout
                    << "Merge Sort is an efficient divide and conquer algorithm that continuously divides the container into new containers with one elements and then merges them together to create a final sorted list.."
                    << "\nThe best, worst, and average time complexity for merge sort is O(n log n)."
                    << "\nThis algorithm was first invented in 1945 by John von Neumann and used in a report in 1948."
                    << "\nSource: https://en.wikipedia.org/wiki/Merge_sort"
                    << std::endl;
        }

            //Time Complexity
        else if (input1choice == 2) {
            //Text to choose to sort 1 column or all columns in dataset
            ColSelect();
            int col;
            cin >> col;

            //One column
            if (col == 1) {
                auto start_time = chrono::high_resolution_clock::now();
                MergeSort(contents, 0, contents.size() - 1, 2);
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " amount of milliseconds to run this sorting algorithm on 1 column.";
            }

                //All columns
            else {
                auto start_time = chrono::high_resolution_clock::now();
                for (int i = 2; i < 9; i++) {
                    MergeSort(contents, 0, contents.size() - 1, i);
                }
                auto end_time = chrono::high_resolution_clock::now();
                auto duration = duration_cast<chrono::milliseconds>(end_time - start_time);
                cout << "It took: " << duration.count() << " amount of milliseconds to run this sorting algorithm.";
            }
        }
    }

    return 0;
}