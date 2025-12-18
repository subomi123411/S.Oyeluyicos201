#include <iostream>
using namespace std;

int main(){
    int year;
    cout <<" Enter a year: ";
    cin >> year;
    switch (year % 12){
        case 0: cout << "Monkey" << endl; break;
        case 1: cout << "Rooster" << endl; break;
        case 2: cout << "Dog" << endl; break;
        case 3: cout << "Pig" << endl; break;
        case 4: cout << "Rat" << endl; break;
        case 5: cout << "Ox" << endl; break;
        case 6: cout << "Tiger" << endl; break;
        case 7: cout << "Rabbit" << endl; break;
        case 8: cout << "Dragon" << endl; break;
        case 9: cout << "Snake" << endl; break;
        case 10: cout << "Horse" << endl; break;
        case 11: cout << "sheep" << endl; break;
    }
    return 0;
}