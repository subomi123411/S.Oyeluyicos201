#include <iostream>
using namespace std;

void t1(); // Function prototype

void t1(){
    static int x = 1; // x is permamently allocated in the memory for the lifetime of the program
    int y = 1;        
    x++;
    y++;
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
}

int main(){
    t1(); // Call function t1
    t1(); // Call function t1 again
    return 0;
}

