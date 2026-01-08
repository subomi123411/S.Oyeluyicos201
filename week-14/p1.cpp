#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    string company;
    int age;

public:
    // Constructor
    Employee(string Name, string Company, int Age) {
        name = Name;
        company = Company;
        age = Age;
    }

    void introduceYourself() {
        cout << "My name is " << name << ", I work at " << company 
             << ", and I am " << age << " years old." << endl;
    }
};

int main() {
    // Using constructor to initialize objects
    Employee emp1 = Employee("Dapo", "PAU", 29);
    emp1.introduceYourself();

    Employee emp2 = Employee("Tope", "Bells", 48);
    emp2.introduceYourself();

    return 0;
}
/*
emp1.name = "Dapo"; Error: 'name' is a private member of 'employee'
     3 types of access modifiers: public, private, protected
     By default, members of a class are private
     To access members outside the class, we need to declare them as public

A constructor is a special member function that is automatically called when an object of the class is created.
It is used to initialize the object's members.
A constructor follows 3 rules:
1. it must have the same name as the class name.
2. A constrcutor does not have a return type.
3. It must have a public access. 
 */
