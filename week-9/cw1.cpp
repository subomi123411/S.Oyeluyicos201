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
   int num, max;
    // read first number to initialize max
    if (!(infile >> max)) {
        cout << "No integers found." << endl;
        return 0;
    }

    while (infile >> num) {
        if (num > max) max = num;
    }

    cout << "Maximum integer: " << max << endl;
    infile.close();
    return 0;
}
