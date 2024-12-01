#include <iostream>
#include "VaccinationManager.h"
#include "VaccinationAggregator.h"
#include "Menu.h"
#include "Vaccination.h"
#include "Const.h"

int main() {
    VaccinationManager manager;
    VaccinationAggregator aggregator;
   
    int choice;

    do {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.create();    break;
            case 2: manager.displayAll();  break;
            case 3: manager.editById();      break;
            case 4: manager.deleteById();    break;
            case 5: 
                cout << "Vaccination with Min Dose: " 
                    << manager.doses[aggregator.findMin(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findMin(manager)].GetDosesAdministered() 
                    << endl;
                break;
            case 6: 
                cout << "Vaccination with Max Dose: " 
                    << manager.doses[aggregator.findMax(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findMax(manager)].GetDosesAdministered() 
                    << endl;
                break;
            case 7: 
                cout << "Vaccination with 2nd Min Dose: " 
                    << manager.doses[aggregator.findSecondMin(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findSecondMin(manager)].GetDosesAdministered() 
                    << endl;
                break;
            case 8: 
                cout << "Vaccination with 2nd Max Dose: " 
                    << manager.doses[aggregator.findSecondMax(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findSecondMax(manager)].GetDosesAdministered() 
                    << endl;
                break;
            case 9:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 9);

    return 0;
}
