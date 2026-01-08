#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    string company;
    int age;

public:
    // Constructor - FIXED: Assign parameters TO member variables
    Employee(string Name, string Company, int Age) {
        name = Name;        
        company = Company;  
        age = Age;          
    }

    void setName(string Name) {
        name = Name;        
    }
    
    string getName() {
        return name;
    }
    
    void setCompany(string Company) {  
        company = Company;             
    }
    
    string getCompany() {
        return company;
    }
    
    void setAge(int Age) {
        if (Age >= 18){  
        age = Age;          
        }
    }
    int getAge() {
        return age;
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

    emp1.setAge(16);// Should not update age  
    cout << emp1.getName() << " is " << emp1.getAge() << " years old." << endl;

    return 0;
}