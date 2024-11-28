#include <string>
#include <iostream>

using std::string;

class Vaccination{
	private:
		string VaccinationId;
		int Dosage;
	
	public:
		bool Equals(const Vaccination& other);
		bool NotEquals(const Vaccination& other);
		bool GreaterThan(const Vaccination& other);
		bool GreaterThanEquals(const Vaccination& other);
		bool LessThan(const Vaccination& other);
		bool LessThanEquals(const Vaccination& other);

		Vaccination(string p_VaccinationId, int p_Dosage);
};


int main() {
    Vaccination v1("V001", 2);
    Vaccination v2("V002", 3);

    std::cout << std::boolalpha;
    std::cout << "Equals: " << v1.Equals(v2) << std::endl;          // Output: false
    std::cout << "NotEquals: " << v1.NotEquals(v2) << std::endl;          // Output: false
    std::cout << "GreaterThan: " << v1.GreaterThan(v2) << std::endl; // Output: false
    std::cout << "GreaterThanEquals: " << v1.GreaterThanEquals(v2) << std::endl; // Output: false
    std::cout << "LessThan: " << v1.LessThan(v2) << std::endl; // Output: true
    std::cout << "LessThanEquals: " << v1.LessThanEquals(v2) << std::endl; // Output: true

    return 0;
}


using std::string;

bool Vaccination::Equals(const Vaccination& other)
{
	return (Dosage == other.Dosage);
}

bool Vaccination::NotEquals(const Vaccination& other)
{
	return (Dosage != other.Dosage);
}

bool Vaccination::GreaterThan(const Vaccination& other)
{
	return (Dosage > other.Dosage);
}

bool Vaccination::GreaterThanEquals(const Vaccination& other)
{
	return (Dosage >= other.Dosage);
}

bool Vaccination::LessThan(const Vaccination& other)
{
	return (Dosage < other.Dosage);
}

bool Vaccination::LessThanEquals(const Vaccination& other)
{
	return (Dosage <= other.Dosage);
}

Vaccination::Vaccination(string p_VaccinationId, int p_Dosage)
{
	VaccinationId = p_VaccinationId;
	Dosage = p_Dosage;

}
