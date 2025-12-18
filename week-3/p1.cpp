#include <iostream>
using namespace std;

int main (){
    int day;
    cout <<"Enter day of the week from 0 - 6: ";
    cin >> day;
    switch(day){
        case 1: //fall through to the next case
        case 2: //fall through to the next case
        case 3: //fall through to the next case
        case 4: //fall through to the next case
        case 5: cout << "Weekday"; break;
        case 0: //fall through to the next case
        case 6: cout <<"weekend";
    }
}