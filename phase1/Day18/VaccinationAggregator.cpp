#include "VaccinationAggregator.h"
#include "VaccinationManager.h"

int VaccinationAggregator::findMin(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int n = manager.numVaccinations;

    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].LessThan(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

int VaccinationAggregator::findMax(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int n = manager.numVaccinations;

    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].GreaterThan(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int VaccinationAggregator::findSecondMin(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int n = manager.numVaccinations;

    int minIndex = findMin(manager);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i) {
        if (i != minIndex) {
            if (arr[i].LessThan(arr[secondMinIndex])) {
                secondMinIndex = i;
            }
        }
    }
    return secondMinIndex;
}

int VaccinationAggregator::findSecondMax(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int n = manager.numVaccinations;

    int maxIndex = findMax(manager);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

    for (int i = 0; i < n; ++i) {
        if (i != maxIndex) {
            if (arr[i].GreaterThan(arr[secondMaxIndex])) {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}
