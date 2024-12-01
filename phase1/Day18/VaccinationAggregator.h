#pragma once
#include "VaccinationManager.h"
class VaccinationAggregator {
public:
    int findMin(VaccinationManager& manager);
    int findMax(VaccinationManager& manager);
    int findSecondMin(VaccinationManager& manager);
    int findSecondMax(VaccinationManager& manager);
};
