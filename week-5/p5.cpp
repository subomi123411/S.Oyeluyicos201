#include <iostream>
#include <cstdlib>
using namespace std;

void generateRandom(int arr[], int size) {
    srand(time(0)); // set a random seed
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10 + 1; // generate random numbers in the range [1, 10]
    }
}

int main() {
    const int size = 8;
    int numbers[size];
    generateRandom(numbers, size);
    // Print array elements
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    return 0;
}