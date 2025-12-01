#include <iostream>
using namespace std;

int main() {
    int size;
    int arr[50];

    cout << "Pls enter the size of the array: ";
    cin >> size; 

    for( int i = 0; i <= size-1; i++) {
        cout << "Enter the value for index " <<i; 
        cin>>arr[i];
    }

    for (int j = 0; j <= size-1; j++) {
        cout << arr[j] << "\t";
    } 
}