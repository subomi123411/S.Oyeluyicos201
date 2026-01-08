#include <iostream>
using namespace std;

int sum(int a, int b){
    cout << "The sum of " << a << " and " << b << " is " << a + b << endl;
    return 0;
}

int main(){
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    sum(num1, num2);
    return 0;
}