#pragma once

#include <string>

using std::string;

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


