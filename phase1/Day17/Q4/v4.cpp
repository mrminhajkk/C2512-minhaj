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
   friend class Comparisons;
};

class Comparisons{
    public:
	 static bool LessThan(const Vaccination& first, const Vaccination& second);
     static bool LessThanEquals(const Vaccination& first, const Vaccination& second);
     static bool GreaterThan(const Vaccination& first, const Vaccination& second);
     static bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
     static bool Equals(const Vaccination& first, const Vaccination& second);
     static bool NotEquals(const Vaccination& first, const Vaccination& second);
};

// Constructor definition outside the class
Vaccination::Vaccination(string p_VaccinationID, int p_DoseAdministered) {
    VaccinationID = p_VaccinationID;
    DoseAdministered = p_DoseAdministered;
}

// Comparison functions
bool Comparisons::LessThan(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered < second.DoseAdministered);
}

bool Comparisons::LessThanEquals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered <= second.DoseAdministered);
}

bool Comparisons::GreaterThan(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered > second.DoseAdministered);
}

bool Comparisons::GreaterThanEquals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered >= second.DoseAdministered);
}

bool Comparisons::Equals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered == second.DoseAdministered);
}

bool Comparisons::NotEquals(const Vaccination& first, const Vaccination& second) {
    return (first.DoseAdministered != second.DoseAdministered);
}

int main() {
    Vaccination vac1("VAC001", 3);
    Vaccination vac2("VAC002", 5);

    cout << std::boolalpha;

    // Test comparison functions
    cout << "LessThan: " << Comparisons::LessThan(vac1, vac2) << endl;             // Output: true
    cout << "LessThanEquals: " << Comparisons::LessThanEquals(vac1, vac2) << endl; // Output: true
    cout << "GreaterThan: " << Comparisons::GreaterThan(vac1, vac2) << endl;       // Output: false
    cout << "GreaterThanEquals: " << Comparisons::GreaterThanEquals(vac1, vac2) << endl; // Output: false
    cout << "Equals: " << Comparisons::Equals(vac1, vac2) << endl;                 // Output: false
    cout << "NotEquals: " << Comparisons::NotEquals(vac1, vac2) << endl;           // Output: true

    return 0;
}
