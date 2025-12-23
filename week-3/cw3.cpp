#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main (){
    int nItems;
    string itemName;
    double itemPrice;
    string lowestItem;
    double lowestPrice = numeric_limits<double>::max();
    string secondLowestItem;
    double secondLowestPrice = numeric_limits<double>::max();

    cout << "Enter the number of items: \n";
    cin >> nItems;

    for (int i = 1; i <= nItems; i++){
        
        cout << "Enter the name of item " << i << ": ";
        cin >> itemName;

        cout << "Enter the price of item " << i << ": ";
        cin >> itemPrice;

        cout << itemName << "\t" << itemPrice << endl;
        
        // New lowest price found
        if (itemPrice < lowestPrice){
            secondLowestPrice = lowestPrice;
            secondLowestItem = lowestItem;

            lowestPrice = itemPrice;
            lowestItem = itemName;
        }

        // New second lowest price found
         else if (itemPrice > lowestPrice && itemPrice < secondLowestPrice) {
            secondLowestPrice = itemPrice;
            secondLowestItem = itemName;
        }
    }

    if (nItems > 1 && secondLowestPrice != numeric_limits<double>::max()){
        cout << "The lowest priced item is " << lowestItem << " with a price of " << lowestPrice << endl;
        cout << "The second lowest priced item is " << secondLowestItem << " with a price of " << secondLowestPrice << endl;
    } else if (nItems == 1) {
        cout << "Only one item entered." << endl;
        cout << "\nPrice of the item is " << itemPrice << " and item name is " << itemName << endl;
    } else {
        cout << "No items entered." << endl;
    }

    return 0;
}