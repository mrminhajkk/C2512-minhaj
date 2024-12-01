#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Vaccination {
private:
    string VaccinationID;  // Renamed from VaccineID
    int DoseAdministered;  // Renamed from NumberOfDoses

public:
    // Constructor declaration
    Vaccination(string p_VaccinationID, int p_DoseAdministered);

    // Friend comparison functions
    friend bool LessThan(const Vaccination& first, const Vaccination& second);
    friend bool LessThanEquals(const Vaccination& first, const Vaccination& second);
    friend bool GreaterThan(const Vaccination& first, const Vaccination& second);
    friend bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
    friend bool Equals(const Vaccination& first, const Vaccination& second);
    friend bool NotEquals(const Vaccination& first, const Vaccination& second);
};

	 bool LessThan(const Vaccination& first, const Vaccination& second);
     bool LessThanEquals(const Vaccination& first, const Vaccination& second);
     bool GreaterThan(const Vaccination& first, const Vaccination& second);
     bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
     bool Equals(const Vaccination& first, const Vaccination& second);
     bool NotEquals(const Vaccination& first, const Vaccination& second);

// Constructor definition outside the class
Vaccination::Vaccination(string p_VaccinationID, int p_DoseAdministered) {
    VaccinationID = p_VaccinationID;
    DoseAdministered = p_DoseAdministered;
}

// Comparison functions
bool LessThan(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered < second.DoseAdministered);
}

bool LessThanEquals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered <= second.DoseAdministered);
}

bool GreaterThan(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered > second.DoseAdministered);
}

bool GreaterThanEquals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered >= second.DoseAdministered);
}

bool Equals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered == second.DoseAdministered);
}

bool NotEquals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered != second.DoseAdministered);
}

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
