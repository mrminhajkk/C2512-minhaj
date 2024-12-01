#pragma once

#include <string>

using std::string;

class HospitalStay {
private:
    string StayID;
    int NumberOfDays;

public:
    // Constructor declaration
    HospitalStay(string p_StayID, int p_NumberOfDays);

    // Friend comparison functions
    friend bool LessThan(const HospitalStay& first, const HospitalStay& second);
    friend bool LessThanEquals(const HospitalStay& first, const HospitalStay& second);
    friend bool GreaterThan(const HospitalStay& first, const HospitalStay& second);
    friend bool GreaterThanEquals(const HospitalStay& first, const HospitalStay& second);
    friend bool Equals(const HospitalStay& first, const HospitalStay& second);
    friend bool NotEquals(const HospitalStay& first, const HospitalStay& second);
};

