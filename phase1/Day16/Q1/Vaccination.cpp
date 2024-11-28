#include <string>

#include "Vaccination.h"

using std::string;

bool Vaccination::Equals(const Vaccination& other)
{
	return (DoseAdministered == other.DoseAdministered);
}

bool Vaccination::NotEquals(const Vaccination& other)
{
	return (DoseAdministered != other.DoseAdministered);
}

bool Vaccination::GreaterThan(const Vaccination& other)
{
	return (DoseAdministered > other.DoseAdministered);
}

bool Vaccination::GreaterThanEquals(const Vaccination& other)
{
	return (DoseAdministered >= other.DoseAdministered);
}

bool Vaccination::LessThan(const Vaccination& other)
{
	return (DoseAdministered < other.DoseAdministered);
}

bool Vaccination::LessThanEquals(const Vaccination& other)
{
	return (DoseAdministered <= other.DoseAdministered);
}

Vaccination::Vaccination(string p_VaccinationId, int p_DoseAdministered)
{
	VaccinationId = p_VaccinationId;
	DoseAdministered = p_DoseAdministered;

}
