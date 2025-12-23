#include <iostream>
using namespace std;

int main (){
    int sum = 0;
    int number = 0;
    while(number < 20){
        number++;
        sum += number;
        if (sum >= 100)
            break;
            cout << "Inside the loop\n";
            cout << "Number: " << number << ", Sum: " << sum << endl;
    }
    cout << "Outside the loop\n";
    cout << "Final Number: " << number << ", Final Sum: " << sum << endl;
    return 0;
}