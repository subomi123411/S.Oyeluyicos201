#include <iostream>
#include <iomanip> 
using namespace std;

int main (){
    int num;
    int sum = 0;
    int count = 0;
    int average;
    int positiveCount = 0;
    int negativeCount = 0;

    cout << "Enter an integer (the input ends if it is 0): \n";
    
    while(cin >> num && num !=0){
        
        
        if(num > 0)
            positiveCount++;
        else
            negativeCount++;
        sum += num;
        count++;
        
            
    }
    if (count != 0){
       double average = static_cast<double>(sum) / count;
        cout << "The number of positives is " << positiveCount << endl;
        cout << "The number of negatives is " << negativeCount << endl;
        cout << "The total is " << sum << endl;
        cout << fixed << setprecision(2);
        cout << "The average is " << average << endl;
    } else {
        cout << "No numbers are entered except 0" << endl;
    }

    return 0;

}
