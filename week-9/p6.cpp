// File Handling in C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
// Reading integers from file
   ifstream infile("integer.txt");
   if(!infile){
         cout << "Cannot open file.";
         return 0;
   }
   int number;
   int sum =0;
   while(infile >> number) {
       cout << number << endl;
       sum += number;
   }
   cout << "Sum: " << sum << endl;
   infile.close();
}