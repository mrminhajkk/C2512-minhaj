
#include "Comparisons.h"


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
