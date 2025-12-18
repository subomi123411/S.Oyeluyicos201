#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double balance;
    double annualInterest;
    double interest;

    cout <<"Enter your starting balance: ";
    cin >> balance;
    cout <<"Enter annual interest rate: ";
    cin >> interest;
    cout <<"\nBalnce is " << balance << " and interest rate is "<< interest << endl;
    annualInterest = balance + (balance * interest)/100;
    cout <<"Balance after one year is: " << annualInterest << endl;
    return 0;
}