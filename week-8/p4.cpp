#include <iostream>
using namespace std;

void readArray(int list[], int size) {
    for( int i = 0; i <= size-1; i++) {
        cout << "Enter the value for index " <<i; 
        cin>>list[i];
    }
}

void nprintArray(int list[], int size) {
    for (int j = 0; j <= size-1; j++) {
        cout << list[j] << "\t";
    } 
}
int addArrays(int list[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i];
    }
    return sum;
}
int main() {
    int size;
    int arr[50];

    cout << "Pls enter the size of the array: ";
    cin >> size; 

    readArray(arr, size);
    nprintArray(arr, size);
    int result = addArrays(arr, size);
    cout << "\nThe sum of the array elements is: " << result;
    
}
// binary search algortithm
// min/max with their index
// linear search algorithm
// random number generation and filling an array with random numbers