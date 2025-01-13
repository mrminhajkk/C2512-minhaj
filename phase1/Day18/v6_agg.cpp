#include <iostream>
#include <iomanip>

using namespace std;

// *****Const.h*****
// Constants
const int MAX_HOSPITAL_doses = 100;
// *****Vaccination.h*****
class Vaccination {
    friend class VaccinationManager;
    private:
        string VaccinationId;
        int DosesAdministered;
    public:
        bool GreaterThan(const Vaccination& other);
        bool LessThan(const Vaccination& other);
         //getters-setters
        string GetVaccinationId();
        int GetDosesAdministered();
};
// *****VaccinationManager.h*****
class VaccinationManager {
    friend class VaccinationAggregator;
    friend int main();
    private:
        // attributes
        Vaccination doses[MAX_HOSPITAL_doses];    
        int numVaccinations;
    public:
        // support
        int findIndexById(string VaccinationId);
        // behaviours
        void create();
        void displayAll();
        void editById();
        void deleteById();
        //
        VaccinationManager();
};
//*****VaccinationAggregator.h*****
class VaccinationAggregator {
    public:
        int findMin(VaccinationManager& manager);
        int findMax(VaccinationManager& manager);
        int findSecondMin(VaccinationManager& manager);
        int findSecondMax(VaccinationManager& manager);
};
// *****Menu.h*****
void printMenu();

// *****Main.cpp*****

int main() {
    VaccinationManager manager;
    VaccinationAggregator aggregator;
   
    int choice; // User's menu choice

    do {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice) {
            case 1: manager.create();    break;
            case 2: manager.displayAll();  break;
            case 3: manager.editById();      break;
            case 4: manager.deleteById();    break;
            case 5: 
                std::cout << "Vaccination with Min Dose: " 
                    << manager.doses[aggregator.findMin(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findMin(manager)].GetDosesAdministered() 
                    << std::endl;
                break;
            case 6: 
                std::cout << "Vaccination with Max Dose: " 
                    << manager.doses[aggregator.findMax(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findMax(manager)].GetDosesAdministered() 
                    << std::endl;
                break;
            case 7: 
                std::cout << "Vaccination with 2nd Min Dose: " 
                    << manager.doses[aggregator.findSecondMin(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findSecondMin(manager)].GetDosesAdministered() 
                    << std::endl;
                break;
            case 8: 
                std::cout << "Vaccination with 2nd Max Dose: " 
                    << manager.doses[aggregator.findSecondMax(manager)].GetVaccinationId() 
                    << " with DosesAdministered " 
                    << manager.doses[aggregator.findSecondMax(manager)].GetDosesAdministered() 
                    << std::endl;
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

// *****VaccinationManager.cpp*****
/**
 * @brief Creates a new hospital stay and stores details in arrays. 
 */
void VaccinationManager::create() {
    if (numVaccinations >= MAX_HOSPITAL_doses) {
        cout << "Error: Maximum hospital stay limit reached.\n";
        return;
    }

    string VaccinationId;
    int DosesAdministered;

    cout << "Enter Vaccination VaccinationId: ";
    cin >> VaccinationId;

    // Ensure hospital stay VaccinationId is unique findindexid in line 167
    if (findIndexById(VaccinationId) != -1) {
        cout << "Error:  VaccinationId already exists. Please use a unique VaccinationId.\n";
        return;
    }

    cout << "Enter DoseAdministered: ";
    cin >> DosesAdministered;

    // Store the hospital stay details
    doses[numVaccinations].VaccinationId = VaccinationId;
    doses[numVaccinations].DosesAdministered = DosesAdministered;
    numVaccinations++;

    cout << "Vaccination created successfully.\n";
}

/**
 * @brief Displays all existing doses in a tabular format.
 */
void VaccinationManager::displayAll() {
    if (numVaccinations == 0) {
        cout << "No doses available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "|   VaccinationId | DoseAdministered                    |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numVaccinations; i++) {
        cout << "| " << setw(10) << doses[i].VaccinationId << " | "
             << setw(13) << doses[i].DosesAdministered << " |\n";
    }
    cout << "------------------------------------------------\n";
}

/**
 * @brief Finds the index of a hospital stay by VaccinationId.
 * @param VaccinationId Vaccination VaccinationId to search for.
 * @return Index of the hospital stay if found, -1 otherwise.
 */
int VaccinationManager::findIndexById(string VaccinationId) {
    for (int i = 0; i < numVaccinations; i++) {
        if (doses[i].VaccinationId == VaccinationId) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Edits an existing hospital stay by VaccinationId.
 */
void VaccinationManager::editById() {
    string VaccinationId;
    cout << "Enter VaccinationId to edit: ";
    cin >> VaccinationId;

    int index = findIndexById(VaccinationId);
    if (index == -1) {
        cout << "Error:  VaccinationId not found.\n";
        return;
    }

    cout << "Current Details - DoseAdministered: " << doses[index].DosesAdministered << "\n";

    cout << "Enter New Dose: ";
    cin >> doses[index].DosesAdministered;

    cout << "Vaccination updated successfully.\n";
}

/**
 * @brief Deletes an existing hospital stay by VaccinationId.
 */
void VaccinationManager::deleteById() {
    string VaccinationId;
    cout << "Enter VaccinationId to delete: ";
    cin >> VaccinationId;

    int index = findIndexById(VaccinationId);
    if (index == -1) {
        cout << "Error: VaccinationId not found.\n";
        return;
    }

    // Shift data to fill the gap
    for (int i = index; i < numVaccinations - 1; i++) {
        doses[i] = doses[i + 1];
    }
    numVaccinations--;

    cout << "Vaccination deleted successfully.\n";
}

VaccinationManager::VaccinationManager() {
    numVaccinations = 0;
}
// *****Menu.cpp*****
void printMenu() {
    cout << "\n=== Vaccination DoseAdministered Management Module ===\n";
    cout << "1. Create Vaccination and DosageAdministered \n";
    cout << "2. Display Vaccination and DoseAdministered\n";
    cout << "3. Edit Vaccination and DoseAdministeredy\n";
    cout << "4. Delete Vaccination and DoseAdministered\n";
    cout << "5. Find Min  DoseAdministered\n";
    cout << "6. Find Max  DoseAdministered\n";
    cout << "7. Find Second Min  DoseAdministered\n";
    cout << "8. Find Second Max  DoseAdministered\n";
    cout << "9. Exit\n";
}

//*****Vaccination.cpp*****
bool Vaccination::GreaterThan(const Vaccination& other)
{
    return (DosesAdministered > other.DosesAdministered);
}

bool Vaccination::LessThan(const Vaccination& other)
{
    return (DosesAdministered < other.DosesAdministered);
}

//getters-setters
string Vaccination::GetVaccinationId()
{
    return VaccinationId;
}
int Vaccination::GetDosesAdministered()
{
    return DosesAdministered;
}
//*****VaccinationAggregator.cpp*****
// Function to find the index of the Vaccination with the minimum years of Stay
int VaccinationAggregator::findMin(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int& n = manager.numVaccinations;
    //
    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].LessThan(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the index of the Vaccination with the maximum years of Stay
int VaccinationAggregator::findMax(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int& n = manager.numVaccinations;
    //
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].GreaterThan(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the Vaccination with the second minimum years of Stay
int VaccinationAggregator::findSecondMin(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int& n = manager.numVaccinations;
    //
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

// Function to find the index of the Vaccination with the second maximum years of Stay
int VaccinationAggregator::findSecondMax(VaccinationManager& manager) {
    Vaccination* arr = manager.doses;
    int& n = manager.numVaccinations;
    //
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

