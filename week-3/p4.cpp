#include <iostream>
using namespace std;

int main (){
    srand(time(0));
    int num1 = rand() % 10;
    int num2 = rand() & 10;
    if(num1 < num2){
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    int value_resp, actual_ans = num1 - num2;
    cout << "What is the value of "<< num1 <<" - " << num2 <<"?";
    cin >> value_resp;
    while(value_resp != actual_ans){
        cout << "Wrong answer. Try again.";
        cin >> value_resp;
    }
    cout<<"You got it!";
    return 0;
    
}