/*
4 Principles of OOP:
a. Encapsulation
b. abstraction
c. Polymorphism
d. Inheritance 

1. ENCAPSULATION - The "Capsule" Principle
What it is:
Encapsulation is the bundling of data (variables) and methods (functions) that operate on that data into a single unit called a class, while restricting direct access to some of the object's components.

Core Concept:
"Information Hiding" - Hide the internal state and require all interaction to go through a controlled interface.

Three Levels of Access Control:
cpp
class Employee {
private:    // Most restricted - only accessible within the class
    double salary;           // Hidden data
    string ssn;             // Sensitive information
    void calculateTax() {   // Internal helper method
        // Complex tax calculation logic
    }

protected:  // Accessible within class and derived classes
    string department;      // Shared with child classes
    int employeeId;         // Internal identifier

public:     // Fully accessible from anywhere
    string name;           // Public information
    int age;               // Public information
    
    // Public interface - controlled access to private data
    void setSalary(double amount) {
        if (amount >= 0) {  // Validation
            salary = amount;
            calculateTax();  // Internal processing
        }
    }
    
    double getSalary() {
        return salary - calculateDeductions();  // Processed data
    }
};
Why Encapsulation Matters:
Data Protection: Prevents invalid or inconsistent state

cpp
// Without encapsulation - problem!
emp.salary = -5000;  // Invalid salary allowed

// With encapsulation - protected!
emp.setSalary(-5000);  // Method can validate and reject
Implementation Independence: You can change internal implementation without affecting users

cpp
// Version 1: Store salary as double
private: double salary;

// Version 2: Changed to store in cents as integer
private: long salaryInCents;
public: void setSalary(double amount) {
    salaryInCents = amount * 100;  // Convert to cents
}
// Users don't know about this change!
Maintainability: Changes are localized to the class

Testing: Easier to test through well-defined interfaces

Real-world Example: Bank ATM
cpp
class ATM {
private:
    double cashAvailable;
    bool validateCard(string cardNumber);
    bool validatePIN(string pin);
    void updateBankBalance(double amount);
    void dispenseCash(double amount);
    
public:
    // Simple public interface
    bool withdrawMoney(string cardNumber, string pin, double amount) {
        if (!validateCard(cardNumber)) return false;
        if (!validatePIN(pin)) return false;
        if (amount > cashAvailable) return false;
        
        updateBankBalance(amount);
        dispenseCash(amount);
        return true;
    }
};
// User interacts ONLY with withdrawMoney(), not internal details
2. ABSTRACTION - The "Simplification" Principle
What it is:
Abstraction is the process of hiding complex implementation details and showing only essential features to the user.

Core Concept:
"Hide complexity, expose simplicity" - Users interact with high-level interfaces without knowing underlying complexities.

Levels of Abstraction:
cpp
// LOW LEVEL (No abstraction - user needs to know everything)
void makeCoffeeManual() {
    boilWater(100, 5);          // User specifies temperature and time
    grindBeans(15, "medium");   // User specifies grams and coarseness
    pourWater(200, 30);         // User specifies ml and pour rate
    // Too many details for just wanting coffee!
}

// HIGH LEVEL (With abstraction)
class CoffeeMachine {
private:
    WaterHeater heater;
    BeanGrinder grinder;
    BrewSystem brewer;
    MilkFrother frother;
    
    // Complex internal processes hidden
    void heatWaterToOptimalTemp() {
        // Uses sensors, PID controllers, etc.
    }
    
    void grindToOptimalFineness() {
        // Motor control, timers, etc.
    }
    
public:
    // Simple interface exposed
    void makeCoffee(string type) {
        if (type == "espresso") makeEspresso();
        else if (type == "latte") makeLatte();
        else if (type == "cappuccino") makeCappuccino();
    }
    
    void makeEspresso() {
        heatWaterToOptimalTemp();   // User doesn't know details
        grindToOptimalFineness();   // User doesn't know details
        // 20 more complex steps...
    }
};

// User simply does:
CoffeeMachine machine;
machine.makeCoffee("latte");  // THAT'S IT!
Types of Abstraction:
Data Abstraction: Hide data representation

cpp
class Date {
private:
    int daysSinceEpoch;  // Hidden representation
public:
    Date(int y, int m, int d) { /* convert to daysSinceEpoch */ }
    int getYear() { /* extract from daysSinceEpoch */ }
    // Users think in year/month/day, not daysSinceEpoch
};
Procedural Abstraction: Hide algorithmic details

Control Abstraction: Hide flow control complexity

Why Abstraction Matters:
Reduces Complexity: Users deal with 10 high-level concepts instead of 1000 low-level details

Increases Reusability: Abstract components can be reused in different contexts

Improves Maintainability: Changes to implementation don't affect users

Enhances Security: Sensitive algorithms/logic are hidden

Real-world Analogy: Car Dashboard
You see: Speedometer, fuel gauge, temperature gauge

Hidden: Engine combustion, transmission gears, fuel injection

You interact with: Steering wheel, pedals, gear shift

Hidden: Hydraulic systems, electrical circuits, mechanical linkages

3. INHERITANCE - The "Family Tree" Principle
What it is:
Inheritance allows a class (child/derived) to inherit properties and behaviors from another class (parent/base), establishing an "is-a" relationship.

Core Concept:
"Code reuse through hierarchy" - Create general classes and extend them for specific cases.

Types of Inheritance:
cpp
// 1. SINGLE INHERITANCE (One parent)
class Vehicle {  // Base class
protected:
    string brand;
    int speed;
public:
    void start() { cout << "Vehicle starting..." << endl; }
    void stop() { cout << "Vehicle stopping..." << endl; }
};

class Car : public Vehicle {  // Derived class
private:
    int doors;
public:
    void drive() { 
        start();  // Inherited method
        cout << "Car driving with " << doors << " doors" << endl;
    }
};

// 2. MULTILEVEL INHERITANCE (Chain)
class Animal {
public:
    void breathe() { cout << "Breathing..." << endl; }
};

class Mammal : public Animal {
public:
    void feedMilk() { cout << "Feeding milk..." << endl; }
};

class Dog : public Mammal {
public:
    void bark() { 
        breathe();    // From Animal
        feedMilk();   // From Mammal  
        cout << "Woof!" << endl;
    }
};

// 3. HIERARCHICAL INHERITANCE (Multiple children)
class Shape {
public:
    virtual double area() = 0;  // Abstract method
};

class Circle : public Shape {
    double radius;
public:
    double area() { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double length, width;
public:
    double area() { return length * width; }
};

class Triangle : public Shape {
    double base, height;
public:
    double area() { return 0.5 * base * height; }
};
// All shapes inherit common interface but implement differently

// 4. MULTIPLE INHERITANCE (Multiple parents - use carefully!)
class Printer {
public:
    void print(string doc) { /* printing logic */ }
};

class Scanner {
public:
    void scan() { /* scanning logic */ }
};

class AllInOne : public Printer, public Scanner {
    // Can both print and scan
};
Inheritance Access Specifiers:
cpp
class Base {
public:     int x;  // Accessible everywhere
protected:  int y;  // Accessible in Base and derived classes
private:    int z;  // Accessible only in Base
};

class Derived : public Base {
    // x remains public
    // y remains protected  
    // z is NOT accessible (remains private to Base)
};

class Derived : protected Base {
    // x becomes protected
    // y remains protected
    // z is NOT accessible
};

class Derived : private Base {
    // x becomes private
    // y becomes private
    // z is NOT accessible
};
Why Inheritance Matters:
Code Reusability: Don't repeat common code

Extensibility: Easily add new features to existing hierarchy

Real-world Modeling: Natural "is-a" relationships

Polymorphism Foundation: Enables runtime polymorphism

The "Liskov Substitution Principle" (Important!):
Objects of a superclass should be replaceable with objects of its subclasses without breaking the application.

cpp
// GOOD inheritance (follows LSP)
class Bird {
public:
    virtual void move() { cout << "Moving..." << endl; }
};

class FlyingBird : public Bird {
public:
    void move() override { cout << "Flying..." << endl; }
};

class Penguin : public Bird {
public:
    void move() override { cout << "Swimming..." << endl; }
};

// BAD inheritance (violates LSP)
class Rectangle {
protected:
    int width, height;
public:
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    int area() { return width * height; }
};

class Square : public Rectangle {  // Problem!
public:
    void setWidth(int w) { 
        width = w; 
        height = w;  // Forced to keep square
    }
    void setHeight(int h) {
        height = h;
        width = h;   // Forced to keep square
    }
};

// This breaks LSP:
void testRectangle(Rectangle& r) {
    r.setWidth(5);
    r.setHeight(4);
    assert(r.area() == 20);  // Fails for Square!
}
4. POLYMORPHISM - The "Many Forms" Principle
What it is:
Polymorphism allows objects of different types to be treated as objects of a common supertype, with the ability to exhibit different behaviors.

Core Concept:
"One interface, multiple implementations" - Same method call, different behaviors.

Two Types of Polymorphism:
A. COMPILE-TIME POLYMORPHISM (Static/Early Binding)
cpp
// 1. FUNCTION OVERLOADING
class Calculator {
public:
    // Same function name, different parameters
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
    
    string add(string a, string b) {
        return a + b;  // Concatenation
    }
};

// 2. OPERATOR OVERLOADING
class Complex {
    double real, imag;
public:
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    
    bool operator==(const Complex& other) {
        return real == other.real && imag == other.imag;
    }
};

// 3. TEMPLATES (Generic Programming)
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}
// maximum(5, 10) works with int
// maximum(3.14, 2.71) works with double
// maximum('a', 'z') works with char
B. RUNTIME POLYMORPHISM (Dynamic/Late Binding)
cpp
// REQUIRES: 1. Inheritance 2. Virtual functions 3. Pointers/References

class Animal {
public:
    // Virtual function - enables runtime polymorphism
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
    
    // Pure virtual function - makes class abstract
    virtual void move() = 0;  // Must be implemented by derived classes
    
    // Virtual destructor - IMPORTANT for proper cleanup
    virtual ~Animal() { cout << "Animal destroyed" << endl; }
};

class Dog : public Animal {
public:
    void makeSound() override {  // Override parent implementation
        cout << "Woof! Woof!" << endl;
    }
    
    void move() override {
        cout << "Running on four legs" << endl;
    }
    
    ~Dog() { cout << "Dog destroyed" << endl; }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow! Meow!" << endl;
    }
    
    void move() override {
        cout << "Walking gracefully" << endl;
    }
    
    ~Cat() { cout << "Cat destroyed" << endl; }
};

class Bird : public Animal {
public:
    void makeSound() override {
        cout << "Chirp! Chirp!" << endl;
    }
    
    void move() override {
        cout << "Flying in the sky" << endl;
    }
    
    ~Bird() { cout << "Bird destroyed" << endl; }
};

// POLYMORPHISM IN ACTION
int main() {
    // Array of base class pointers pointing to different derived objects
    Animal* zoo[3];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Bird();
    
    for (int i = 0; i < 3; i++) {
        zoo[i]->makeSound();  // SAME call, DIFFERENT behaviors
        zoo[i]->move();       // SAME call, DIFFERENT behaviors
        // Output:
        // Woof! Woof!
        // Running on four legs
        // Meow! Meow!
        // Walking gracefully
        // Chirp! Chirp!
        // Flying in the sky
    }
    
    // Cleanup - virtual destructor ensures proper destruction
    for (int i = 0; i < 3; i++) {
        delete zoo[i];
    }
}
Virtual Function Mechanism (V-Table):
cpp
// How it works internally:
class Animal {
    // Compiler adds hidden pointer: vptr (virtual pointer)
    // vptr points to vtable (virtual table)
};

// vtable for Animal class:
// [0] -> Animal::makeSound()
// [1] -> Animal::move()

// vtable for Dog class:
// [0] -> Dog::makeSound()   // Overridden
// [1] -> Dog::move()        // Overridden

// When calling zoo[i]->makeSound():
// 1. Follow vptr to vtable
// 2. Look up makeSound() in vtable
// 3. Call appropriate function based on actual object type
Why Polymorphism Matters:
Flexibility: Write generic code that works with multiple types

Extensibility: Add new types without modifying existing code

Interface Consistency: Uniform interface for related objects

Framework Design: Essential for libraries and frameworks

Real-world Example: Payment Processing
cpp
class Payment {
public:
    virtual bool process(double amount) = 0;
    virtual ~Payment() {}
};

class CreditCard : public Payment {
public:
    bool process(double amount) override {
        cout << "Processing credit card: $" << amount << endl;
        // Contact bank, verify, charge card
        return true;
    }
};

class PayPal : public Payment {
public:
    bool process(double amount) override {
        cout << "Processing PayPal: $" << amount << endl;
        // Redirect to PayPal, handle callback
        return true;
    }
};

class Bitcoin : public Payment {
public:
    bool process(double amount) override {
        cout << "Processing Bitcoin: " << amount << " BTC" << endl;
        // Blockchain transaction
        return true;
    }
};

class ShoppingCart {
    vector<Payment*> payments;
public:
    void checkout(Payment* paymentMethod, double total) {
        // Doesn't know which payment method is used
        if (paymentMethod->process(total)) {
            cout << "Payment successful!" << endl;
        }
        // Can add new payment methods without changing this code
    }
};
HOW ALL 4 PRINCIPLES WORK TOGETHER
cpp
// ENCAPSULATION: Data hidden in private sections
// ABSTRACTION: Complex details hidden, simple interface exposed
// INHERITANCE: Common features in base class
// POLYMORPHISM: Same interface, different implementations

class Employee {  // ABSTRACT BASE CLASS
private:  // ENCAPSULATION
    string name;
    int id;
    double baseSalary;
    
protected:  // For derived classes
    virtual double calculateBonus() = 0;  // ABSTRACTION: Hide calculation details
    
public:
    Employee(string n, int i, double s) : name(n), id(i), baseSalary(s) {}
    
    // POLYMORPHISM: Virtual function
    virtual double calculatePay() {  // Can be overridden
        return baseSalary + calculateBonus();
    }
    
    virtual void work() = 0;  // Pure virtual - ABSTRACTION
    
    string getName() { return name; }  // ENCAPSULATION: Getter
};

// INHERITANCE: Specialized employees
class Developer : public Employee {
private:
    string programmingLanguage;
    
protected:
    double calculateBonus() override {  // ENCAPSULATION: Implementation hidden
        return 5000;  // Developers get fixed bonus
    }
    
public:
    Developer(string n, int i, double s, string lang)
        : Employee(n, i, s), programmingLanguage(lang) {}
    
    void work() override {  // POLYMORPHISM: Different implementation
        cout << "Writing code in " << programmingLanguage << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;
    
protected:
    double calculateBonus() override {  // ENCAPSULATION
        return teamSize * 1000;  // Bonus based on team size
    }
    
public:
    Manager(string n, int i, double s, int team)
        : Employee(n, i, s), teamSize(team) {}
    
    void work() override {  // POLYMORPHISM
        cout << "Managing team of " << teamSize << " people" << endl;
    }
};

class Salesperson : public Employee {
private:
    double salesAmount;
    
protected:
    double calculateBonus() override {  // ENCAPSULATION
        return salesAmount * 0.1;  // 10% commission
    }
    
public:
    Salesperson(string n, int i, double s, double sales)
        : Employee(n, i, s), salesAmount(sales) {}
    
    void work() override {  // POLYMORPHISM
        cout << "Making sales calls, current sales: $" << salesAmount << endl;
    }
};

// USING THE SYSTEM
int main() {
    vector<Employee*> company;
    
    // POLYMORPHISM: Different types in same container
    company.push_back(new Developer("Alice", 101, 80000, "C++"));
    company.push_back(new Manager("Bob", 102, 100000, 5));
    company.push_back(new Salesperson("Charlie", 103, 60000, 50000));
    
    // ABSTRACTION: Simple interface
    for (Employee* emp : company) {
        cout << emp->getName() << ": ";
        emp->work();  // POLYMORPHISM: Different behaviors
        cout << "Pay: $" << emp->calculatePay() << endl;  // POLYMORPHISM
    }
    
    // OUTPUT:
    // Alice: Writing code in C++
    // Pay: $85000
    // Bob: Managing team of 5 people
    // Pay: $105000
    // Charlie: Making sales calls, current sales: $50000
    // Pay: $65000
}
*/