#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include <iomanip>
#include <sstream>

namespace sdds {
	class Car :public Vehicle {
	private:
		std::string m_maker{};
		std::string m_condition{}; // could be enum
		int m_topSpeed{};

	public:
		Car();
		Car(std::istream& input);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
;	};
}
#endif