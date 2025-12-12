#include <iostream>
using namespace std;
int main() {
    srand(time(0)); // Seed for random number generation
    cout << rand() << endl; // Print a random number
    cout << rand() % 10 << endl; // Print a random number between 0 and 9
    return 0;
}