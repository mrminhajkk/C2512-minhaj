#pragma once
#include <string>

using std::string;

class Comparisons;  // Forward declaration of Comparisons class

class Vaccination {
private:
    string VaccinationID;  // Renamed from VaccineID
    int DoseAdministered;  // Renamed from NumberOfDoses

public:
    // Constructor declaration
    Vaccination(string p_VaccinationID, int p_DoseAdministered);

    // Declare Comparisons class as a friend
    friend class Comparisons;
};

