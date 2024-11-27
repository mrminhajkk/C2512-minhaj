#include <iostream>
#include <iomanip>

#include "Vaccination.h"

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
