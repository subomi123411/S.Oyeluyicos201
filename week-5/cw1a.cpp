#include <iostream>
#include <cstdlib>
#include <cstring> // for cstring functions
using namespace std;

int main (){
    // concatenation
    cout << "Concatenation Example:" << endl;

    // using strcat concatenates entire strings
    char dest[50] = "Hello, ";
    char src1[] = "World!";
    strcat(dest, src1); 
    cout << "strcat result: " << dest << endl;

    // using strncat concatenates only n characters
    char dest2[50] = "Programming in ";
    char src2[] = "C++ is fun.";
    strncat(dest2, src2, 5); // only concatenates first 5 characters of src2
    cout << "\nstrncat result: " << dest2 << endl;

    // Safe concatenation with buffer size checking
    char dest3[20] = "Hello";
    char src3[] = ", welcome to C++ programming!";
    strncat(dest3, src3, 14); // Only concatenate what fits in buffer
    cout << "\nSafe strncat result: " << dest3 << endl;

    // comparison
    cout << "\nComparison Example:" << endl;
    char str1[] = "apple";
    char str2[] = "apple";
    char str3[] = "banana";
    char str4[] = "Apple";  // Note: Capital 'A'

    // comparing equal strings
    int result1 = strcmp(str1, str2);
    cout << "comparing 'apple' with 'apple': "<< result1;
    if (result1 == 0) 
    cout << "(Strings are equal)" << endl;

    // comparing different strings
    int result2 = strcmp(str1, str3);
    cout << "comparing 'apple' with 'banana': "<< result2;
    if (result2 < 0)
    cout << "('Apple' comes before 'banana')" << endl;

    // comparing strings with different cases
    int result3 = strcmp(str1, str4);
    cout << "comparing 'apple' with 'Apple': "<< result3;
    if (result3 > 0)
    cout << "('apple' comes after 'Apple' in ASCII order)" << endl;

    // Comparing partial strings
    int result4 = strncmp(str3, "ban", 3); // Compare first 3 characters
    cout << "Comparing first 3 chars of 'banana' with 'ban': " << result4;
    if (result4 == 0) {
        cout << " (First 3 characters are equal)" << endl;
    }
    cout << endl;
    return 0;
}