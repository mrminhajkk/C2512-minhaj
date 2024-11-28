#include <string>

#pragma once

using std::string;

class Vaccination{
	private:
		string VaccinationId;
		int DoseAdministered;
	
	public:
		bool Equals(const Vaccination& other);
		bool NotEquals(const Vaccination& other);
		bool GreaterThan(const Vaccination& other);
		bool GreaterThanEquals(const Vaccination& other);
		bool LessThan(const Vaccination& other);
		bool LessThanEquals(const Vaccination& other);

		Vaccination(string p_VaccinationId, int p_DoseAdministered);
};


