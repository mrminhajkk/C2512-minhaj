#include <iostream>
#include <iomanip>
#include "Vaccination.h"
#include "HospitalStay.h"

using std::cout;
using std::endl;

int main() {
    Vaccination vac1("VAC001", 3);
    Vaccination vac2("VAC002", 5);
    HospitalStay hs1("HS001", 5); 
    HospitalStay hs2("HS002", 7);

    cout << std::boolalpha;

    // Test comparison functions for HospitalStay
    cout << "============HOSPITALSTAY COMPARISONS==============" << endl;
    cout << "HospitalStay LessThan: " << LessThan(hs1, hs2) << endl; // Output: true
    cout << "HospitalStay LessThanEquals: " << LessThanEquals(hs1, hs2) << endl;
    cout << "HospitalStay GreaterThan: " << GreaterThan(hs1, hs2) << endl;
    cout << "HospitalStay GreaterThanEquals: " << GreaterThanEquals(hs1, hs2) << endl;
    cout << "HospitalStay Equals: " << Equals(hs1, hs2) << endl;
    cout << "HospitalStay NotEquals: " << NotEquals(hs1, hs2) << endl;

    // Test comparison functions for Vaccination
    cout << "============VACCINATION COMPARISONS===================" << endl;
    cout << "LessThan: " << LessThan(vac1, vac2) << endl;             // Output: true
    cout << "LessThanEquals: " << LessThanEquals(vac1, vac2) << endl; // Output: true
    cout << "GreaterThan: " << GreaterThan(vac1, vac2) << endl;       // Output: false
    cout << "GreaterThanEquals: " << GreaterThanEquals(vac1, vac2) << endl; // Output: false
    cout << "Equals: " << Equals(vac1, vac2) << endl;                 // Output: false
    cout << "NotEquals: " << NotEquals(vac1, vac2) << endl;           // Output: true

    return 0;
}
