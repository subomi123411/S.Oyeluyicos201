#include <iostream>
using namespace std;
int num1;
int num2;
int answer;
int main() {
    cout << "Enter two integers between 0 and 9: ";
    cin >> num1 >> num2;
    cout << "You entered: " << num1 << " and " << num2 << endl;
    if (num1 < num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
        cout << "After swapping, first number: " << num1 << ", second number: " << num2 << endl;
    }
    cout << "What is number1 - number2?" << endl;
    cin >> answer;
    if (answer == num1 - num2) {
        cout << "Correct!" << endl;
    } 
    else {
        cout << "Incorrect!" << endl;
    }
    return 0;
}
