#include <iostream>
#include <string>
#include <climits>

class Vaccination {
public:
    std::string VaccinationID;
    int DosesAdministered;

   
    Vaccination(std::string id, int doses);

   
    friend int findMinDoses(Vaccination vaccinations[], int size);
    friend int findMaxDoses(Vaccination vaccinations[], int size);
    friend int findSecondMinDoses(Vaccination vaccinations[], int size);
    friend int findSecondMaxDoses(Vaccination vaccinations[], int size);
};


Vaccination::Vaccination(std::string id, int doses) {
    VaccinationID = id;
    DosesAdministered = doses;
}


int findMinDoses(Vaccination vaccinations[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].DosesAdministered < vaccinations[minIndex].DosesAdministered) {
            minIndex = i;
        }
    }
    return minIndex;
}


int findMaxDoses(Vaccination vaccinations[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].DosesAdministered > vaccinations[maxIndex].DosesAdministered) {
            maxIndex = i;
        }
    }
    return maxInd
