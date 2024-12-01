#include "Vaccination.h"

bool Vaccination::GreaterThan(const Vaccination& other) {
    return (DosesAdministered > other.DosesAdministered);
}

bool Vaccination::LessThan(const Vaccination& other) {
    return (DosesAdministered < other.DosesAdministered);
}

// Getters
string Vaccination::GetVaccinationId() {
    return VaccinationId;
}

int Vaccination::GetDosesAdministered() {
    return DosesAdministered;
}
