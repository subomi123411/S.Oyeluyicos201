#include <iostream>
using namespace std;

int main () {
    int a = 123456789;
    int b = 123456789;
    int c = a + b;
    short d = 1234;
    short e = 1234;
    short f = d + e;
    long g = 123456789;
    long h = 123456789;
    long i = g + h;

    cout << "int addition: " << c << endl;
    cout << "short addition: " << f << endl;
    cout << "long addition: " << i << endl;
    
    return 0;
}