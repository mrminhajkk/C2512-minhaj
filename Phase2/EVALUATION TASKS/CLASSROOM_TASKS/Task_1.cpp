#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Vaccination {
    private:
        string VaccinationId;
        int DoseAdministered;
    public:
        Vaccination(string id, int dose) : VaccinationId(id), DoseAdministered(dose) {}

        string getVaccinationId() const {
            return VaccinationId;
        }

        int getDoseAdministered() const {
            return DoseAdministered;
        }
};

int findsum(const vector<Vaccination>& vacc) {
    int sum = 0;
    for (const auto& each : vacc) {
        sum += each.getDoseAdministered();
    }
    return sum;
}

void find_min_in_firsthalf(const vector<Vaccination>& vacc, int& min) {
    min = INT_MAX;
    for (int i = 0; i < vacc.size() / 2; ++i) {
        if (vacc[i].getDoseAdministered() < min) {
            min = vacc[i].getDoseAdministered();
        }
    }
}

void find_max_in_secondhalf(const vector<Vaccination>& vacc, int& max) {
    max = INT_MIN;
    for (int i = vacc.size() / 2; i < vacc.size(); ++i) {
        if (vacc[i].getDoseAdministered() > max) {
            max = vacc[i].getDoseAdministered();
        }
    }
}

int main() {
    vector<Vaccination> vacc = { Vaccination("P001", 11), Vaccination("P002", 5), Vaccination("P003", 6), Vaccination("P004", 15), Vaccination("P005", 1) };
    
    int sum = findsum(vacc);
    cout << "The sum is " << sum << endl;

    int min;
    find_min_in_firsthalf(vacc, min);
    cout << "The min in first half is " << min << endl;

    int max;
    find_max_in_secondhalf(vacc, max);
    cout << "The max in second half is " << max << endl;

    return 0;
}
