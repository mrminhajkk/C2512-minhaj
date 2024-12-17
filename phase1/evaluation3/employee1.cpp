#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;        // Employee ID
    int age;       // Employee age
    string name;   // Employee name

public:
    // Parameterized Constructor
    Employee(int empId, int empAge, const string& empName) 
        : id(empId), age(empAge), name(empName) {}

    // Overload << operator for displaying Employee details
    friend ostream& operator<<(ostream& os, const Employee& emp) {
        os << emp.id << " " << emp.age << " " << emp.name;
        return os;
    }

    // Swap function to swap two Employee objects
    void swap(Employee& other) {
        // Swap the id
        int tempId = id;
        id = other.id;
        other.id = tempId;

        // Swap the age
        int tempAge = age;
        age = other.age;
        other.age = tempAge;

        // Swap the name
        string tempName = name;
        name = other.name;
        other.name = tempName;
    }
};

int main() {
    // Creating Employee objects
    Employee e1(101, 22, "Athira");
    Employee e2(102, 23, "Bhagya");

    // Display initial Employee details
    cout << "Before swapping:" << endl;
    cout << e1 << endl; // 101 22 Athira
    cout << e2 << endl; // 102 23 Bhagya

    // Swapping Employee objects
    e1.swap(e2);

    // Display Employee details after swapping
    cout << "After swapping:" << endl;
    cout << e1 << endl; // 102 23 Bhagya
    cout << e2 << endl; // 101 22 Athira

    return 0;
}