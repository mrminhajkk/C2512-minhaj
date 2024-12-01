#pragma once

#include "Vaccination.h"

class Comparisons {
public:
    static bool LessThan(const Vaccination& first, const Vaccination& second);
    static bool LessThanEquals(const Vaccination& first, const Vaccination& second);
    static bool GreaterThan(const Vaccination& first, const Vaccination& second);
    static bool GreaterThanEquals(const Vaccination& first, const Vaccination& second);
    static bool Equals(const Vaccination& first, const Vaccination& second);
    static bool NotEquals(const Vaccination& first, const Vaccination& second);
};


