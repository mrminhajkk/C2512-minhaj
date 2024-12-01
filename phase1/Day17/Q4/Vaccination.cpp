#include "Vaccination.h"
#include <string>

// Constructor definition outside the class
Vaccination::Vaccination(std::string p_VaccinationID, int p_DoseAdministered) {
    VaccinationID = p_VaccinationID;
    DoseAdministered = p_DoseAdministered;
}
