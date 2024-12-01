#include <string>
#include "Vaccination.h"

using std::string;

// Constructor definition outside the class
Vaccination::Vaccination(string p_VaccinationID, int p_DosesAdministered)
    : VaccinationID(p_VaccinationID), DosesAdministered(p_DosesAdministered) {}

// Getter functions to access private members
string Vaccination::getVaccinationID() const {
    return VaccinationID;
}

int Vaccination::getDosesAdministered() const {
    return DosesAdministered;
}

// Friend functions to find the required values

// Find the index of the minimum doses administered
int findMinDoses(Vaccination vaccinations[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].getDosesAdministered() < vaccinations[minIndex].getDosesAdministered()) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Find the index of the maximum doses administered
int findMaxDoses(Vaccination vaccinations[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].getDosesAdministered() > vaccinations[maxIndex].getDosesAdministered()) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Find the index of the second minimum doses administered
int findSecondMinDoses(Vaccination vaccinations[], int size) {
    int minIndex = findMinDoses(vaccinations, size);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < size; ++i) {
        if (i != minIndex) {
            if (vaccinations[i].getDosesAdministered() < vaccinations[secondMinIndex].getDosesAdministered()) {
                secondMinIndex = i;
            }
        }
    }
    return secondMinIndex;
}

// Find the index of the second maximum doses administered
int findSecondMaxDoses(Vaccination vaccinations[], int size) {
    int maxIndex = findMaxDoses(vaccinations, size);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < size; ++i) {
        if (i != maxIndex) {
            if (vaccinations[i].getDosesAdministered() > vaccinations[secondMaxIndex].getDosesAdministered()) {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}
