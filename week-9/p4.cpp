// File Handling in C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
// ofstream ==> write to a file (output)
// ifstream ==> read from a file (input)
// fstream  ==> read and write to a file (input and output)  
    fstream file("data.txt", ios::out | ios::app);
//ios::out ==> Write mode
//ios::app ==> append mode 
//ios::trunc ++> erase file before writing
//ios::in ==> read mode
    file <<"Please add this new line\n";
    file.close();
    cout <<"DONE"<<endl;
}

