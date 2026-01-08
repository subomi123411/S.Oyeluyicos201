#include <iostream>
using namespace std;

void printSum(int a, int b){
    cout << "The sum of " << a << " and " << b << " is " << a + b << endl;
}
int main(){
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    printSum(num1, num2);
    return 0;
}