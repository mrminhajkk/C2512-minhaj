#include "HospitalStay.h"

// Constructor definition
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays) {
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}

// Comparison functions for HospitalStay class
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
