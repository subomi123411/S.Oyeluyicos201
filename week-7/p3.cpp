/*#include <iostream>
#include <string>
using namespace std;

void printPattern(string name, int iteration){
    cout<< name;
}
int main(){
    int i = 1;
    while (i <= 5){
        printPattern("Welcome to c++\n", i);
        i++;
    }
    return 0;
}*/
#include <iostream>
#include <string>
using namespace std;

void nprint(char name, int n){
    for(int i = 1; i<=n; i++){
        cout<< name;
    }
}
int main(){
    nprint('w', 5);
    nprint(6,'w');
}
