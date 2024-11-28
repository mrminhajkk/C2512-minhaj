#include <iostream>
#include <string>
#include <climits>

class Vaccination {
private:
    std::string VaccinationID;
    int DosesAdministered;

public:
    // Constructor declaration
    Vaccination(std::string id, int doses);

    // Declare Comparisons class as a friend so it can access private members
    friend class Comparisons;
};

// Constructor definition outside the class
Vaccination::Vaccination(std::string id, int doses) {
    VaccinationID = id;
    DosesAdministered = doses;
}

// Now we define the Comparisons class outside of Vaccination class

class Comparisons {
public:
    static int findMinDoses(Vaccination vaccinations[], int size);
    static int findMaxDoses(Vaccination vaccinations[], int size);
    static int findSecondMinDoses(Vaccination vaccinations[], int size);
    static int findSecondMaxDoses(Vaccination vaccinations[], int size);
};

// Function to find the index of the vaccination with the minimum doses administered
int Comparisons::findMinDoses(Vaccination vaccinations[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].DosesAdministered < vaccinations[minIndex].DosesAdministered) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the index of the vaccination with the maximum doses administered
int Comparisons::findMaxDoses(Vaccination vaccinations[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].DosesAdministered > vaccinations[maxIndex].DosesAdministered) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the vaccination with the second minimum doses administered
int Comparisons::findSecondMinDoses(Vaccination vaccinations[], int size) {
    int minIndex = findMinDoses(vaccinations, size);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < size; ++i) {
        if (i != minIndex && vaccinations[i].DosesAdministered < vaccinations[secondMinIndex].DosesAdministered) {
            secondMinIndex = i;
        }
    }
    
    return secondMinIndex;
}

// Function to find the index of the vaccination with the second maximum doses administered
int Comparisons::findSecondMaxDoses(Vaccination vaccinations[], int size) {
    int maxIndex = findMaxDoses(vaccinations, size);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < size; ++i) {
        if (i != maxIndex && vaccinations[i].DosesAdministered > vaccinations[secondMaxIndex].DosesAdministered) {
            secondMaxIndex = i;
        }
    }
    
    return secondMaxIndex;
}

int main() {
    Vaccination vaccinations[] = {
        Vaccination("V001", 2),
        Vaccination("V002", 3),
        Vaccination("V003", 1),
        Vaccination("V004", 5),
        Vaccination("V005", 4)
    };

    int size = sizeof(vaccinations) / sizeof(vaccinations[0]);

    // Output the vaccination records based on required conditions
    std::cout << std::boolalpha;

    // Find and output the minimum doses
    int minIndex = Comparisons::findMinDoses(vaccinations, size);
    std::cout << "Min Doses: " << vaccinations[minIndex].DosesAdministered << std::endl;  // Output: 1
    
    // Find and output the maximum doses
    int maxIndex = Comparisons::findMaxDoses(vaccinations, size);
    std::cout << "Max Doses: " << vaccinations[maxIndex].DosesAdministered << std::endl;  // Output: 5
    
    // Find and output the second minimum doses
    int secondMinIndex = Comparisons::findSecondMinDoses(vaccinations, size);
    std::cout << "2nd Min Doses: " << vaccinations[secondMinIndex].DosesAdministered << std::endl;  // Output: 2
    
    // Find and output the second maximum doses
    int secondMaxIndex = Comparisons::findSecondMaxDoses(vaccinations, size);
    std::cout << "2nd Max Doses: " << vaccinations[secondMaxIndex].DosesAdministered << std::endl;  // Output: 4

    return 0;
}
