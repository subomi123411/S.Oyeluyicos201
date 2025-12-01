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
int main() {
    int size;
    int arr[50];

    cout << "Pls enter the size of the array: ";
    cin >> size; 

    readArray(arr, size);
    nprintArray(arr, size);
    
        
    for( int i = 0; i <= size-1; i++) {
        cout << "\nEnter the value for index " <<i; 
        cin>>arr[i];
    }

    for (int j = 0; j <= size-1; j++) {
        cout << arr[j] << "\t";
    } 
}