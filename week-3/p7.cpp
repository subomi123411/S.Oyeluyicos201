#include <iostream>
#include <iomanip> // for setw() function
using namespace std;

int main (){
    cout << "Multiplication Table\n";
    cout << "===================================================\n";

    // Display the number titles
    cout << " | ";
    for(int j = 1; j <= 12; j++){
        cout << setw(4) << j;
    }
    
    cout << "\n";
    for(int i = 1; i <= 12; i++){
        cout << " | ";
        // Display the product and align properly
        for(int j = 1; j <= 12; j++){
            cout << setw(4) << i * j;
        }
        cout << "\n";
    }
    return 0;
}