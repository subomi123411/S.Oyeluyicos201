#include <iostream>
using namespace std;

void findAll(int list[], int key, int size) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (list[i] == key) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "-1";
    }
}

int main() {
    int list[] = {1, 4, 4, 2, 5, -3, 6, 2};

    cout << "Locations of 4: ";
    findAll(list, 4, 8);
}
