#include <iostream>
using namespace std;

// Return the max of two int values
double max(int num1, int num2) {
    if (num1 > num2)
        return num1;
    else
        return num2;
}

// Return the max of two double values
double max(double num1, double num2) {
    if (num1 > num2)
        return num1;
    else
        return num2;
}

// Return the max of three double values
double max(double num1, double num2, double num3) {
    return max(max(num1, num2), num3);
}

int main() {
    // invoke the max functions with int parameters 
    cout << "The max of 3 and 4 is " << max(3, 4) << endl;

    // invoke the max functions with double parameters
    cout << "The max of 3.0 and 5.4 is " << max(3.0, 5.4) << endl;

    // invoke the max functions with three double parameters
    cout << "The max of 3.0, 10.4, and 5.14 is " << max(3.0, 5.4, 10.4) << endl;

    return 0;
}