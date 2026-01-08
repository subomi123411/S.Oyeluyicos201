#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main (){
    cout << "String/Number Conversion Example:" << endl;

    // String to Integer conversion using atoi
    char numStr1[] = "12345";
    char numStr2[] = "99.75"; // Note: atoi will stop at the decimal point
    char numStr3[] = "123abc"; 
    char invalidStr[] = "abc123";

    int intValue = atoi(numStr1);
    cout << "atoi(\"12345\") = " << intValue << endl;

    // atoi stops at decimal point
    int partalInt = atoi(numStr3);
    cout << "atoi(\"123abc\") = " << partalInt << "(stops at 'a')" << endl;

    // Invalid conversion 
    int invalidInt = atoi(invalidStr);
    cout << "atoi(\"abc123\") = " << invalidInt << " (returns 0 for invalid input)" << endl;

       // String to double using atof
    double doubleValue = atof(numStr2);
    cout << "\natof(\"99.75\") = " << doubleValue << endl;
    
    double mixedDouble = atof(numStr3);
    cout << "atof(\"123abc\") = " << mixedDouble << endl;
    
    // String to long using atol
    char bigNum[] = "2147483647";
    long longValue = atol(bigNum);
    cout << "\natol(\"2147483647\") = " << longValue << endl;
    
    // String to long long using atoll
    char biggerNum[] = "9223372036854775807";
    long long longLongValue = atoll(biggerNum);
    cout << "atoll(\"9223372036854775807\") = " << longLongValue << "\n\n";
    
    // ==================== PRACTICAL EXAMPLE ====================
    cout << "========== PRACTICAL EXAMPLE ==========\n\n";
    
    // Simulating user input processing
    char userInput[100] = "Add 25 and 37";
    cout << "Processing user input: \"" << userInput << "\"" << endl;
    
    // Extract numbers from string
    char* token = strtok(userInput, " ");
    char numbers[2][10];
    int numCount = 0;
    
    while (token != nullptr && numCount < 2) {
        // Check if token is a number
        if (atoi(token) != 0 || strcmp(token, "0") == 0) {
            strcpy(numbers[numCount], token);
            numCount++;
        }
        token = strtok(nullptr, " ");
    }
    
    if (numCount == 2) {
        int a = atoi(numbers[0]);
        int b = atoi(numbers[1]);
        cout << "Extracted numbers: " << a << " and " << b << endl;
        cout << "Sum: " << a + b << endl;
    }
    
    // ==================== SAFETY CONSIDERATIONS ====================
    cout << "\n========== SAFETY CONSIDERATIONS ==========\n\n";
    cout << "Important notes:\n";
    cout << "1. Always ensure destination buffers are large enough for strcat\n";
    cout << "2. Use strncat for safer concatenation with length limits\n";
    cout << "3. atoi/atof return 0 for invalid input - check input validity\n";
    cout << "4. Consider using C++ string class for better safety and convenience\n";
    
    return 0;
}
