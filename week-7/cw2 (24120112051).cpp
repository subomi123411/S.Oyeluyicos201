#include <iostream>
using namespace std;

void displayMenu() {
                cout<<"\n--- ATM Menu ---" << endl;
                cout<<"1. Check Balance" << endl;
                cout<<"2. Withdraw Cash" << endl;
                cout<<"3. Deposit Cash" << endl;
                cout<<"4. Reset PIN" << endl;
                cout<<"5. Exit" << endl;
                cout<<"\nPlease select an option (1-5): ";
            }

int main(){
    double accBalnce = 50000.00;
    double withdrawLimit = 20000.00;
    int userPIN = 4321;
    bool pinCorrect = false;
    int attempts = 0;
    string loginStat = "Logged Out";
    int userChoice;


    cout<<" \nEnter your PIN: ";
    cin>> userPIN;
    
    while (attempts < 3 && !pinCorrect){
        if (userPIN == 4321){
            pinCorrect = true;
            int userChoice = 0;

            loginStat = "Logged In";
            cout<<" \nYou can proceed with your transaction." << endl;

            do {
                displayMenu();
                cin>> userChoice;
                
                switch (userChoice) {
                    case 1: {
                        cout<<" \nYour current balance is: " << accBalnce << endl;
                        break;
                    }

                    case 2: {
                        double withdrawAmount;
                        cout<<" \nEnter amount to withdraw: ";
                        cin>> withdrawAmount;
                        if (withdrawAmount > withdrawLimit){
                            cout<<" \nWithdrawal amount exceeds the limit of " << withdrawLimit << endl;
                        }
                        else if (withdrawAmount > accBalnce){
                            cout<<" \nInsufficient balance." << endl;
                        }
                        else{
                            accBalnce -= withdrawAmount;
                            cout<<" \nPlease collect your cash. Your new balance is: " << accBalnce << endl;
                        }
                        break;
                    }

                    case 3: {
                        double depositAmount;
                        cout<<" \nEnter amount to deposit: ";
                        cin>> depositAmount;
                        accBalnce += depositAmount;
                        cout<<" \nDeposit successful. Your new balance is: " << accBalnce << endl;
                        break;
                    }

                    case 4: {
                        int newPIN;
                        cout<<" \nEnter your current PIN: ";
                        cin>> userPIN;
                        while (userPIN != 4321){
                            cout<<" \nIncorrect PIN. Please try again: ";
                            cin>> userPIN;
                        }
                        cout<<" \nEnter your new PIN: ";
                        cin>> newPIN;
                        userPIN = newPIN;
                        cout<<" \nPIN reset successful." << endl;
                        break;
                    }
                    case 5: {
                        cout<<" \nThank you for using the ATM. Goodbye!" << endl;
                        break;
                    }
                    default:
                        cout<<" \nInvalid choice. Please try again." << endl;
                }
            } 
            while (userChoice != 5);
        }
        else{
            cout<<" \nIncorrect PIN. Please try again: ";
            cin>> userPIN;
            attempts++;
        }
    }
    if (pinCorrect == false){
        cout<<" \nYour account is locked due to multiple incorrect PIN attempts. Please contact your bank." << endl;
    }
    return 0;
}