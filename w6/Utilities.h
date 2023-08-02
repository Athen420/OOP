#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
#include <iomanip>

namespace sdds {
	Vehicle* createInstance(std::istream& in);
	std::string trim(std::string input);
}