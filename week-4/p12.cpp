#include <iostream>
using namespace std;

// Return the max between two numbers
int max(const int& num1, const int& num2) {
    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}
int main() {
    int a = 10;
    int b = 20;
    cout << "The maximum between " << a << " and " << b << " is " << max(a, b) << endl;
    return 0;
}