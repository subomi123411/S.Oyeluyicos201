#include <iostream>
using namespace std;

int square(int n) {
    return n * n;
}
int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    cout << "The square of " << number << " is " << square(number) << endl;
    return 0;
}
