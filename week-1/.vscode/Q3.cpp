#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double hypotenuse, side1, side2;
    cout << "Enter the length of the two sides of the right triangle: ";
    cin >> side1 >> side2;
    hypotenuse = sqrt((side1 * side1) + (side2 * side2));
    cout << "The length of the hypotenuse is: " << hypotenuse << endl;
    return 0;
}