#include <iostream>
#include "Vaccination.h"
#include "Comparisons.h"

using std::cout;
using std::endl;

int main() {
    Vaccination vac1("VAC001", 3);
    Vaccination vac2("VAC002", 5);

    cout << std::boolalpha;

    // Test comparison functions using Comparisons class
    cout << "LessThan: " << Comparisons::LessThan(vac1, vac2) << endl;             // Output: true
    cout << "LessThanEquals: " << Comparisons::LessThanEquals(vac1, vac2) << endl; // Output: true
    cout << "GreaterThan: " << Comparisons::GreaterThan(vac1, vac2) << endl;       // Output: false
    cout << "GreaterThanEquals: " << Comparisons::GreaterThanEquals(vac1, vac2) << endl; // Output: false
    cout << "Equals: " << Comparisons::Equals(vac1, vac2) << endl;                 // Output: false
    cout << "NotEquals: " << Comparisons::NotEquals(vac1, vac2) << endl;           // Output: true

    return 0;
}
