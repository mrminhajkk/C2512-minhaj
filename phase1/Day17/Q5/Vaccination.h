#pragma once
#include <string>

using std::string;

class Vaccination {
private:
    string VaccinationID;   // Private member
    int DosesAdministered;  // Private member

public:
    // Constructor declaration
    Vaccination(string p_VaccinationID, int p_DosesAdministered);

    // Getter functions to access private members
    string getVaccinationID() const;
    int getDosesAdministered() const;

    // Friend functions to access private members
    friend int findMinDoses(Vaccination vaccinations[], int size);
    friend int findMaxDoses(Vaccination vaccinations[], int size);
    friend int findSecondMinDoses(Vaccination vaccinations[], int size);
    friend int findSecondMaxDoses(Vaccination vaccinations[], int size);
};


