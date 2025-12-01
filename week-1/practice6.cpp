#include <iostream>
using namespace std;
int a = 40;
int b = 30;         
int main ()
{
    {
        int a = 2;
        int b = 4;
        cout <<"Inner block a: "<< a <<endl;
        cout <<"Inner block b: "<< b <<endl;
    }
        cout <<"Outer block a: "<< a << endl;
        cout <<"Outer block b: "<< b << endl;
        return 0; 
}
