// File Handling in C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
// ofstream ==> write to a file (output)
// ifstream ==> read from a file (input)
// fstream  ==> read and write to a file (input and output)
    
    ifstream infile("data.txt");

    if(!infile) {
        cout << "Error opening file.";
        return 0;
    }
    string line;
    int count = 0;
    while(getline(infile, line)) {
        cout << line << endl;
        count++;
    }
    cout<< "The number of lines are "<< count;
    infile.close();

    cout <<"\nDONE";
}

