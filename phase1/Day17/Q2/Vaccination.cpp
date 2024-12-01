#include "Vaccination.h"
#include <string>

using std::string;

// Constructor definition
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
