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

class HospitalStay {
    private:
        string StayID;
        int NumberOfDays;
    public:
        //constructor
        HospitalStay(string p_StayID, int p_NumberOfDays);
        //friends
        friend bool LessThan(const HospitalStay& first, const HospitalStay& second);
        friend bool LessThanEquals(const HospitalStay& first, const HospitalStay& second);
        friend bool GreaterThan(const HospitalStay& first, const HospitalStay& second);
        friend bool GreaterThanEquals(const HospitalStay& first, const HospitalStay& second);
        friend bool Equals(const HospitalStay& first, const HospitalStay& second);
        friend bool NotEquals(const HospitalStay& first, const HospitalStay& second);
};
//"************"HospitalStayComparisons.h"************
bool LessThan(const HospitalStay& first, const HospitalStay& second);
bool LessThanEquals(const HospitalStay& first, const HospitalStay& second);
bool GreaterThan(const HospitalStay& first, const HospitalStay& second);
bool GreaterThanEquals(const HospitalStay& first, const HospitalStay& second);
bool Equals(const HospitalStay& first, const HospitalStay& second);
bool NotEquals(const HospitalStay& first, const HospitalStay& second);

HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}

bool LessThan(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays < second.NumberOfDays);
}

bool LessThanEquals(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays <= second.NumberOfDays);
}

bool GreaterThan(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays > second.NumberOfDays);
}

bool GreaterThanEquals(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays >= second.NumberOfDays);
}

bool Equals(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays == second.NumberOfDays);
}

bool NotEquals(const HospitalStay& first, const HospitalStay& second) {
    return (first.NumberOfDays != second.NumberOfDays);
}

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
    HospitalStay hs1("HS001", 5); HospitalStay hs2("HS002", 7);

    cout << std::boolalpha;

    // Test comparison functions
    cout << "============HOSPITALSTAY COMPARISONS==============" << endl;
    cout << "HospitalStay LessThan: " << LessThan(hs1, hs2) << endl; // Output: true
    cout << "HospitalStay LessThanEquals: " << LessThanEquals(hs1, hs2) << endl;
    cout << "HospitalStay GreaterThan: " << GreaterThan(hs1, hs2) << endl;
    cout << "HospitalStay GreaterThanEquals: " << GreaterThanEquals(hs1, hs2) << endl;
    cout << "HospitalStay Equals: " << Equals(hs1, hs2) << endl;
    cout << "HospitalStay NotEquals: " << NotEquals(hs1, hs2) << endl;

    cout << "============VACCINATION COMPARISONS===================" << endl;
    cout << "LessThan: " << LessThan(vac1, vac2) << endl;             // Output: true
    cout << "LessThanEquals: " << LessThanEquals(vac1, vac2) << endl; // Output: true
    cout << "GreaterThan: " << GreaterThan(vac1, vac2) << endl;       // Output: false
    cout << "GreaterThanEquals: " << GreaterThanEquals(vac1, vac2) << endl; // Output: false
    cout << "Equals: " << Equals(vac1, vac2) << endl;                 // Output: false
    cout << "NotEquals: " << NotEquals(vac1, vac2) << endl;           // Output: true

    return 0;
}
