#include <iostream>
using namespace std;

int main() {
    cout << "Enter an integer: ";
    int number;
    cin >> number;
    cout << "You entered: " << number << endl;

    if (number % 5 == 0 ){
        cout << "HiFive" << endl;
    }
    else if (number % 2 == 0 ){
        cout << "HiEven" << endl;
    }
    else {
        cout << "HiOdd" << endl;
    }
    return 0; 
} 
