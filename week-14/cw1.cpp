#include <iostream>
using namespace std;

class Cars {
private:
    string name;
    string company;
    string color;
    int yearMade;

public:
    // Constructor - FIXED: Assign parameters TO member variables
    Cars(string Name, string Company, int YearMade, string Color) {
        name = Name;        
        company = Company;  
        yearMade = YearMade;   
        color=Color;      
    }

    // Setter methods - FIXED: Parameter on right, member on left
    void setName(string Name) {
        name = Name;        
    }
    
    string getName() {
        return name;
    }
    
    void setCompany(string Company) {  
        company = Company;             
    }
    void setColor(string Color) {  
        color = Color;             
    }
    
    string getCompany() {
        return company;
    }

    void setYear(int YearMade) {  
        yearMade = YearMade;          

    }
    int getYear() {
        return yearMade;
    }
    string getColor() {
        return color;
    }

    void carInfo() {
        cout << "Car name is " << name << ", made by " << company 
             << ", and it was made in " << yearMade<<" and it is " << color << endl;
    }
};

int main() {
    
    Cars car1 = Cars("Camry", "Toyota", 2010,"red");
    car1.carInfo();

    Cars car2 = Cars("Civic", "Honda", 2018,"blue");
    car2.carInfo();
    cout << car1.getName() << " was made in " << car1.getYear()<< endl;

    return 0;
}