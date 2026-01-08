#include <iostream>
using namespace std;

void printArray(float list[], int size) {
    for(int i = 0; i < size; i++) {
        cout << list[i] << " \t";
    }
}

int main() {
    float scores[10] = {35.0, 88.5, 76.0, 77.0, 80.0, 92.0, 58.0, 45.5, 67.5, 84.0};
    scores[0]++;
    printArray(scores, 10);
    return 0;
}