#include <iostream>
using namespace std;

// Base class
class Person {
private:
    string secret; // only Person can access this
    
protected:
    int age; // Person and its derived classes can access this
    
public:
    string name; // accessible everywhere

    // Constructor
    Person(string n, int a, string s) {
        name = n;
        age = a;
        secret = s;
    }

    // Public function can access private data
    void revealSecret() {
        cout << "Secret: " << secret << endl;
    }
};

// Derived class (Student inherits from Person)
class Student : public Person {
public:
    int rollNo;

    // Constructor calling base class constructor
    Student(string n, int a, string s, int r) : Person(n, a, s) {
        rollNo = r;
    }

    void showDetails() {
        cout << "Name: " << name << endl;    // public (allowed)
        cout << "Age: " << age << endl;      // protected (allowed in derived)
        // cout << secret; // ❌ NOT allowed (private)
        cout << "Roll No: " << rollNo << endl;
    }
};

// Further derived class
class GraduateStudent : public Student {
public:
    string specialization;

    GraduateStudent(string n, int a, string s, int r, string sp) 
        : Student(n, a, s, r) {
        specialization = sp;
    }

    void display() {
        cout << "Graduate Student Info:" << endl;
        showDetails();
        cout << "Specialization: " << specialization << endl;
    }
};

int main() {
    // Create an object of GraduateStudent
    GraduateStudent gs("Alice", 22, "Likes coffee", 101, "Computer Science");

    // Accessing public data directly
    cout << "Name (public): " << gs.name << endl;

    // Accessing through public function
    gs.revealSecret(); // Accesses private member indirectly

    // Display all details
    gs.display();

    return 0;
}
