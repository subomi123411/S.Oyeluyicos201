#include <iostream>
using namespace std;

inline void triple(int a){
    cout << "The triple of " << a << " is " << 3 * a << endl;
}
int main(){
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    triple(number);
    return 0;
}
    