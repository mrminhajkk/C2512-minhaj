#include <iostream>
#include "Vaccination.h"

using std::cout;
using std::endl;

int main() {
    Vaccination vac1("VAC001", 3);
    Vaccination vac2("VAC002", 5);

    cout << std::boolalpha;

    // Test comparison functions
    cout << "LessThan: " << LessThan(vac1, vac2) << endl;             // Output: true
    cout << "LessThanEquals: " << LessThanEquals(vac1, vac2) << endl; // Output: true
    cout << "GreaterThan: " << GreaterThan(vac1, vac2) << endl;       // Output: false
    cout << "GreaterThanEquals: " << GreaterThanEquals(vac1, vac2) << endl; // Output: false
    cout << "Equals: " << Equals(vac1, vac2) << endl;                 // Output: false
    cout << "NotEquals: " << NotEquals(vac1, vac2) << endl;           // Output: true

    return 0;
}
