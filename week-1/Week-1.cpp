// my first program in c++
// p1
#include <iostream>
using namespace std;

int a = 40;
int b = 30;
int main(){
    cout << " Hello world";

    //p2
    double radius;
    double area;

    //step1:Read in radius
    radius = 20;

    // step2: Compute area
    area = radius * radius * 3.14159;

    // step3: Display the area
    cout <<"\n The area of the circle is: "<< area<< endl;

    //p3
    // step1: Read in radius

    cout << "Enter radius: ";
    cin >> radius;

    // step2: Compute area
    area = radius * radius * 3.14159;

    cout << "The area of the circle is: " << area << endl;
    
    //p4
    //Prompt the user to enter 3 numbers
    double number1, number2, number3;
    cout<<"Enter three numbers:"<< endl;
    cout<<"\nFirst number: ";
    cin >> number1;
    cout<<"\nSecond number: ";
    cin >> number2;
    cout <<"\nThird number: ";
    cin >> number3;

    // Compute average
    double average = (number1 + number2 + number3) / 3;
    
    // Display results
    cout <<"The average of " << number1 << " " << number2
        << " " << number3 << " is " << average << endl;

    //p5
    //Compute the first area
    radius = 1.0;
    area = radius * radius * 3.14159;
    cout<<" The area is "<< area <<" for radius "<< radius<<endl;

    //Compute the second area
    radius = 2.0;
    area = radius * radius * 3.14159;
    cout<<" The area is "<< area <<" for radius "<< radius<<endl;

   return 0;
}