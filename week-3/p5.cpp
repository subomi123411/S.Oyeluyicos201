#include <iostream>
using namespace std;

int main (){
    int sum = 0, data = 0;
    do{
        sum += data;
        cout << "Enter an integer (input ends if it is 0): ";
        cin >> data;
    } while (data != 0);
    cout << "The sum is " << sum << endl;
    return 0;
}