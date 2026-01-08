#include <iostream>
using namespace std;

void nPrint(char ch, int n) {
    for (int i = 0; i < n; i++) {
        cout << ch << endl;
    }

}
int main() {
    cout << "Enter a character: ";
    char ch;
    cin >> ch;
    cout << "Enter a number: ";
    int n;
    cin >> n;
    nPrint(ch, n);
    return 0;
}