#pragma once
#include <string>

using namespace std;

class Vaccination {
    friend class VaccinationManager;
private:
    string VaccinationId;
    int DosesAdministered;
public:
    bool GreaterThan(const Vaccination& other);
    bool LessThan(const Vaccination& other);

    // Getters
    string GetVaccinationId();
    int GetDosesAdministered();
};
