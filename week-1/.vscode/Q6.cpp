#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double balance;
    double int1;
    double interest;
    double int2;

    cout <<"Enter your starting balance: ";
    cin >> balance;
    cout <<"Enter annual interest rate: ";
    cin >> interest;
    cout <<"Balnce is " << balance << " and interest rate is "<< interest <<endl;
    int1 = balance + (balance * interest)/100;
    int2 = balance + (balance * interest * 2)/100;
    cout <<"\nBalance after one year is: " << int1 << endl;
    cout <<"Balance after two years is: " << int2 << endl;
    return 0;
}