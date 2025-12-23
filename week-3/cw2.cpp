#include <iostream>
#include <string>
using namespace std;

int main (){
    int nItems;
    string itemName;
    double itemPrice;
    string lowestItem;
    double lowestPrice = INT_MAX;

    cout << "Enter the number of items: ";
    cin >> nItems;

    for (int i = 1; i <= nItems; i++){
        cout << "Enter the name of item " << i << ": ";
        cin >> itemName;
        cout << "Enter the price of item " << i << ": ";
        cin >> itemPrice;
        cout << itemName << "\t" << itemPrice << endl;
        
        if (itemPrice < lowestPrice){
            lowestPrice = itemPrice;
            lowestItem = itemName;
        }
    }

    if (nItems > 1){
        cout << "The lowest priced item is " << lowestItem << " with a price of " << lowestPrice << endl;
    } else if (nItems == 1) {
        cout << "Only one item entered." << endl;
    } else {
        cout << "No items entered." << endl;
    }

    return 0;
}