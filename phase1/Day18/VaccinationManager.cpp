#include "VaccinationManager.h"
#include "Const.h"
#include "Vaccination.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

VaccinationManager::VaccinationManager() {
    numVaccinations = 0;
}

int VaccinationManager::findIndexById(string VaccinationId) {
    for (int i = 0; i < numVaccinations; i++) {
        if (doses[i].GetVaccinationId() == VaccinationId) {
            return i;
        }
    }
    return -1;
}

void VaccinationManager::create() {
    if (numVaccinations >= MAX_HOSPITAL_doses) {
        cout << "Error: Maximum hospital stay limit reached.\n";
        return;
    }

    string VaccinationId;
    int DosesAdministered;

    cout << "Enter Vaccination VaccinationId: ";
    cin >> VaccinationId;

    if (findIndexById(VaccinationId) != -1) {
        cout << "Error: VaccinationId already exists. Please use a unique VaccinationId.\n";
        return;
    }

    cout << "Enter DoseAdministered: ";
    cin >> DosesAdministered;

    doses[numVaccinations].VaccinationId = VaccinationId;
    doses[numVaccinations].DosesAdministered = DosesAdministered;
    numVaccinations++;

    cout << "Vaccination created successfully.\n";
}

void VaccinationManager::displayAll() {
    if (numVaccinations == 0) {
        cout << "No doses available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "|   VaccinationId | DoseAdministered                    |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numVaccinations; i++) {
        cout << "| " << setw(10) << doses[i].GetVaccinationId() << " | "
             << setw(13) << doses[i].GetDosesAdministered() << " |\n";
    }
    cout << "------------------------------------------------\n";
}

void VaccinationManager::editById() {
    string VaccinationId;
    cout << "Enter VaccinationId to edit: ";
    cin >> VaccinationId;

    int index = findIndexById(VaccinationId);
    if (index == -1) {
        cout << "Error: VaccinationId not found.\n";
        return;
    }

    cout << "Current Details - DoseAdministered: " << doses[index].GetDosesAdministered() << "\n";
    cout << "Enter New Dose: ";
    cin >> doses[index].DosesAdministered;

    cout << "Vaccination updated successfully.\n";
}

void VaccinationManager::deleteById() {
    string VaccinationId;
    cout << "Enter VaccinationId to delete: ";
    cin >> VaccinationId;

    int index = findIndexById(VaccinationId);
    if (index == -1) {
        cout << "Error: VaccinationId not found.\n";
        return;
    }

    for (int i = index; i < numVaccinations - 1; i++) {
        doses[i] = doses[i + 1];
    }
    numVaccinations--;

    cout << "Vaccination deleted successfully.\n";
}
