#include <iostream>
using namespace std;

// Function prototype
double max(double num1, double num2);

int main() {
    cout << "The max of 3.0 and 5.4 is " << max(3.0, 5.4) << endl;
    return 0;
}

// Return the max of two double values
double max(double num1, double num2) {
    if (num1 > num2)
        return num1;
    else
        return num2;
}