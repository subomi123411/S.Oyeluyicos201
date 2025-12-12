#include <iostream>
using namespace std;
int age;
int main() {
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18) {
        cout << "You are an adult." << endl;
    } 
    else {
        cout << "You are not an adult." << endl;
    }
    return 0;
}