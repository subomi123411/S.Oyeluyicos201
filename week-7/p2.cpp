#include <iostream>
#include <string>
using namespace std;

void nprint(string name){
    cout<< name;
}

int add (int a, int b){
    int sum = a + b;
    return sum;
}
int main(){
    nprint("Ibidapo");
    int result = add(12, 18);
}