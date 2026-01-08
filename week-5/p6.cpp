#include <iostream>
#include <cstdlib>
using namespace std;

int linearSearch(const int list[], int key, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (key == list[i]) // if this condition is true read what happens below
            return i; // Out of the function, return the index i, will not execute "return -1;"
        }
    return -1; // key not found
}
int main() {
    int list[] = {1, 4, 4, 2, 5, -3, 6, 2};
    int i = linearSearch(list, 4, 8);
    int j = linearSearch(list, -4, 8);
    int k = linearSearch(list, -3, 8);
    cout << "Location of 4, -4 and -3 are: " << i << ", " << j << ", " << k << endl;
    return 0;
}
/*
Key points to remember (important for exams)

Linear search returns the first occurrence

return immediately exits the function

-1 means element not found

Array indexing starts at 0

*/