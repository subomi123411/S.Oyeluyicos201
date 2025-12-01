#include <iostream>
using namespace std;
int main(){
    //Enter degree in Fahrenheit
    double Fahrenheit;
    cout <<"Enter degree in Fahrenheit: ";
    cin >> Fahrenheit;

    //Obtain a celsisus degree
    double celsius = (5.0/9)*(Fahrenheit - 32);
    
    // Display result
    cout << " fahrenheit " << celsius << " in Celsius" << endl;

    return 0;
}