#include <iostream>
#include <iomanip>
#include "Vaccination.h"

using std::cout;
using std::endl;

int main() {
    Vaccination vaccinations[] = {
        Vaccination("V001", 2),
        Vaccination("V002", 3),
        Vaccination("V003", 1),
        Vaccination("V004", 5),
        Vaccination("V005", 4)
    };

    int size = 5;
    
    std::cout << std::boolalpha;
    
    // Finding and printing the desired results using the getter function
    std::cout << "Min Doses: " << vaccinations[findMinDoses(vaccinations, size)].getDosesAdministered() << std::endl;  // Output: 1
    std::cout << "Max Doses: " << vaccinations[findMaxDoses(vaccinations, size)].getDosesAdministered() << std::endl;  // Output: 5
    std::cout << "2nd Min Doses: " << vaccinations[findSecondMinDoses(vaccinations, size)].getDosesAdministered() << std::endl;  // Output: 2
    std::cout << "2nd Max Doses: " << vaccinations[findSecondMaxDoses(vaccinations, size)].getDosesAdministered() << std::endl;  // Output: 4

    return 0;
}
