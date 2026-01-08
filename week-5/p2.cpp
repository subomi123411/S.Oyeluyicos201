#include <iostream>
using namespace std;

int main() {
    float numbers[8] = {12.5, 15.0, 22.5, 30.0, 18.5, 25.0, 10.0, 20.0};
    float max = numbers[0];
    float min = numbers[0];
    for(int i = 1; i < 8; i++){
        if(numbers[i] > max){
            max = numbers[i];
        }
        if(numbers[i] < min){
            min = numbers[i];
        }
    }
    cout << "The largest number is: " << max << endl;
    cout << "The smallest number is: " << min << endl;
    return 0;    
}