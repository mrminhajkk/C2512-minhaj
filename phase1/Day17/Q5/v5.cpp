#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Vaccination {
private:
    string VaccinationID;  
    int DosesAdministered;  

public:
   
    Vaccination(string p_VaccinationID, int p_DosesAdministered);

   
    string getVaccinationID() const;
    int getDosesAdministered() const;

    friend int findMinDoses(Vaccination vaccinations[], int size);
    friend int findMaxDoses(Vaccination vaccinations[], int size);
    friend int findSecondMinDoses(Vaccination vaccinations[], int size);
    friend int findSecondMaxDoses(Vaccination vaccinations[], int size);
};


Vaccination::Vaccination(string p_VaccinationID, int p_DosesAdministered)
    : VaccinationID(p_VaccinationID), DosesAdministered(p_DosesAdministered) {}


string Vaccination::getVaccinationID() const {
    return VaccinationID;
}

int Vaccination::getDosesAdministered() const {
    return DosesAdministered;
}


int findMinDoses(Vaccination vaccinations[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].getDosesAdministered() < vaccinations[minIndex].getDosesAdministered()) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMaxDoses(Vaccination vaccinations[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (vaccinations[i].getDosesAdministered() > vaccinations[maxIndex].getDosesAdministered()) {
            maxIndex = i;
        }
    }
    return maxIndex;
}


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
    
    
    std::cout << "Min Doses: " << vaccinations[findMinDoses(vaccinations, size)].getDosesAdministered() << std::endl;  
    std::cout << "Max Doses: " << vaccinations[findMaxDoses(vaccinations, size)].getDosesAdministered() << std::endl; 
    std::cout << "2nd Min Doses: " << vaccinations[findSecondMinDoses(vaccinations, size)].getDosesAdministered() << std::endl;  
    std::cout << "2nd Max Doses: " << vaccinations[findSecondMaxDoses(vaccinations, size)].getDosesAdministered() << std::endl;  

    return 0;
}
