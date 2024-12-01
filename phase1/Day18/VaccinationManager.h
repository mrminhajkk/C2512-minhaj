#pragma once
#include "Vaccination.h"
#include "Const.h"

class VaccinationManager {
    friend class VaccinationAggregator;
    friend int main();
private:
    Vaccination doses[MAX_HOSPITAL_doses];
    int numVaccinations;
public:
    int findIndexById(string VaccinationId);

    void create();
    void displayAll();
    void editById();
    void deleteById();

    VaccinationManager();
};
