#include <iostream>
#include <deque>
#include <algorithm>
#include <iomanip>

using namespace std;

// Constants
const int MAX_VACCINATION_DOSE = 100;

// Vaccination class definition
class Vaccination {
    friend class VaccinationManager;
    private:
        string VaccinationId;
        int DosesAdministered;

    public:
        // Getters and setters
        string GetVaccinationId() { return VaccinationId; }
        int GetDosesAdministered() { return DosesAdministered; }
};

// VaccinationManager class definition
class VaccinationManager {
    friend int main();
    private:
        // Using deque to store vaccinations
        deque<Vaccination> doses;

    public:
        // Support
        int findIndexById(const string& VaccinationId);
        
        // Behaviors
        void create();
        void displayAll();
        void editById();
        void deleteById();
        
        VaccinationManager() {}
};

// Function to print the menu
void printMenu() {
    cout << "\n=== Vaccination Dose Management Module ===\n";
    cout << "1. Create Vaccination and Dosage\n";
    cout << "2. Display Vaccination and Dose\n";
    cout << "3. Edit Vaccination and Dose\n";
    cout << "4. Delete Vaccination and Dose\n";
    cout << "5. Exit\n";
}

// VaccinationManager function implementations
void VaccinationManager::create() {
    if (doses.size() >= MAX_VACCINATION_DOSE) {
        cout << "Error: Maximum vaccination dose limit reached.\n";
        return;
    }

    string VaccinationId;
    int DosesAdministered;

    cout << "Enter Vaccination VaccinationId: ";
    cin >> VaccinationId;

    // Ensure unique VaccinationId using findIndexById function
    if (findIndexById(VaccinationId) != -1) {
        cout << "Error: VaccinationId already exists. Please use a unique VaccinationId.\n";
        return;
    }

    cout << "Enter DoseAdministered: ";
    cin >> DosesAdministered;

    // Store the vaccination details using push_back
    Vaccination newVaccination;
    newVaccination.VaccinationId = VaccinationId;
    newVaccination.DosesAdministered = DosesAdministered;
    doses.push_back(newVaccination);

    cout << "Vaccination created successfully.\n";
}

void VaccinationManager::displayAll() {
    if (doses.empty()) {
        cout << "No doses available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "|   VaccinationId | DoseAdministered                    |\n";
    cout << "------------------------------------------------\n";
    for (const auto& vaccination : doses) {
        cout << "| " << setw(10) << vaccination.VaccinationId << " | "
             << setw(13) << vaccination.DosesAdministered << " |\n";
    }
    cout << "------------------------------------------------\n";
}

int VaccinationManager::findIndexById(const string& VaccinationId) {
    // Simple alternative using a loop to find the index
    for (int i = 0; i < doses.size(); ++i) {
        if (doses[i].VaccinationId == VaccinationId) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
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

    cout << "Current Details - DoseAdministered: " << doses[index].DosesAdministered << "\n";

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

    // Erase the vaccination from the deque
    doses.erase(doses.begin() + index);

    cout << "Vaccination deleted successfully.\n";
}

// Main function
int main() {
    VaccinationManager manager;

    int choice; // User's menu choice

    do {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice) {
            case 1: manager.create(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.editById(); break;
            case 4: manager.deleteById(); break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}








// #include <iostream>
// #include <deque>
// #include <algorithm>
// #include <iomanip>

// using namespace std;

// // Constants
// const int MAX_VACCINATION_DOSE = 100;

// // Vaccination class definition
// class Vaccination {
//     friend class VaccinationManager;
// private:
//     string VaccinationId;
//     int DosesAdministered;

// public:
//     // Getters and setters
//     string GetVaccinationId() { return VaccinationId; }
//     int GetDosesAdministered() { return DosesAdministered; }
// };

// // VaccinationManager class definition
// class VaccinationManager {
//     friend int main();
// private:
//     // Using deque to store vaccinations
//     deque<Vaccination> doses;

// public:
//     // Support
//     int findIndexById(const string& VaccinationId);

//     // Behaviors
//     void create();
//     void displayAll();
//     void editById();
//     void deleteById();

//     VaccinationManager() {}
// };

// // Function to print the menu
// void printMenu() {
//     cout << "\n=== Vaccination Dose Management Module ===\n";
//     cout << "1. Create Vaccination and Dosage\n";
//     cout << "2. Display Vaccination and Dose\n";
//     cout << "3. Edit Vaccination and Dose\n";
//     cout << "4. Delete Vaccination and Dose\n";
//     cout << "5. Exit\n";
// }

// // VaccinationManager function implementations
// void VaccinationManager::create() {
//     if (doses.size() >= MAX_VACCINATION_DOSE) {
//         cout << "Error: Maximum vaccination dose limit reached.\n";
//         return;
//     }

//     string VaccinationId;
//     int DosesAdministered;

//     cout << "Enter Vaccination VaccinationId: ";
//     cin >> VaccinationId;

//     // Ensure unique VaccinationId using findIndexById function
//     if (findIndexById(VaccinationId) != -1) {
//         cout << "Error: VaccinationId already exists. Please use a unique VaccinationId.\n";
//         return;
//     }

//     cout << "Enter DoseAdministered: ";
//     cin >> DosesAdministered;

//     // Store the vaccination details using push_back
//     Vaccination newVaccination;
//     newVaccination.VaccinationId = VaccinationId;
//     newVaccination.DosesAdministered = DosesAdministered;
//     doses.push_back(newVaccination);

//     cout << "Vaccination created successfully.\n";
// }

// void VaccinationManager::displayAll() {
//     if (doses.empty()) {
//         cout << "No doses available to display.\n";
//         return;
//     }

//     cout << "------------------------------------------------\n";
//     cout << "|   VaccinationId | DoseAdministered                    |\n";
//     cout << "------------------------------------------------\n";
//     for (const auto& vaccination : doses) {
//         cout << "| " << setw(10) << vaccination.VaccinationId << " | "
//              << setw(13) << vaccination.DosesAdministered << " |\n";
//     }
//     cout << "------------------------------------------------\n";
// }

// int VaccinationManager::findIndexById(const string& VaccinationId) {
//     // Using std::find with iterators to find the VaccinationId
//     auto it = find_if(doses.begin(), doses.end(), [&VaccinationId](const Vaccination& v) {
//         return v.VaccinationId == VaccinationId;
//     });

//     if (it != doses.end()) {
//         return distance(doses.begin(), it);  // Return the index if found
//     }

//     return -1; // Return -1 if not found
// }

// void VaccinationManager::editById() {
//     string VaccinationId;
//     cout << "Enter VaccinationId to edit: ";
//     cin >> VaccinationId;

//     int index = findIndexById(VaccinationId);
//     if (index == -1) {
//         cout << "Error: VaccinationId not found.\n";
//         return;
//     }

//     cout << "Current Details - DoseAdministered: " << doses[index].DosesAdministered << "\n";

//     cout << "Enter New Dose: ";
//     cin >> doses[index].DosesAdministered;

//     cout << "Vaccination updated successfully.\n";
// }

// void VaccinationManager::deleteById() {
//     string VaccinationId;
//     cout << "Enter VaccinationId to delete: ";
//     cin >> VaccinationId;

//     int index = findIndexById(VaccinationId);
//     if (index == -1) {
//         cout << "Error: VaccinationId not found.\n";
//         return;
//     }

//     // Erase the vaccination from the deque
//     doses.erase(doses.begin() + index);

//     cout << "Vaccination deleted successfully.\n";
// }

// // Main function
// int main() {
//     VaccinationManager manager;

//     int choice; // User's menu choice

//     do {
//         printMenu(); // Display menu
//         cout << "Enter your choice: ";
//         cin >> choice;

//         // Menu-driven functionality
//         switch (choice) {
//             case 1: manager.create(); break;
//             case 2: manager.displayAll(); 
