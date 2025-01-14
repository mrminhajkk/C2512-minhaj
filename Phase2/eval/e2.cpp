#include <iostream>
#include <vector>
#include <climits>
#include <thread>

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

void findsum(const vector<Vaccination>& vacc, int& sum) {
    sum = 0;
    for (const auto& each : vacc) {
        sum += each.getDoseAdministered();
    }
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
    
    int sum, min, max;

    thread t1(findsum, ref(vacc), ref(sum));
    thread t2(find_min_in_firsthalf, ref(vacc), ref(min));
    thread t3(find_max_in_secondhalf, ref(vacc), ref(max));

    t1.join();
    t2.join();
    t3.join();

    cout << "The sum is " << sum << endl;
    cout << "The min in first half is " << min << endl;
    cout << "The max in second half is " << max << endl;

    return 0;
}
