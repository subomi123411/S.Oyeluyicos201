#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double pamount;
    double tax;
    cout <<"\nEnter total purchase amount"<< endl;
    cin >> pamount;
    tax = 1.06 * pamount;
    cout <<"Amount entered is "<< pamount<< endl;
    cout <<"\nAmount to pay after sales tax is "<< tax << endl; 
    return 0;
}