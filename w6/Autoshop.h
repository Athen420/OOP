#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Vehicle.h"
#include <vector>
#include <list>

namespace sdds {
	class Autoshop {
	private:
		std::vector<Vehicle*> m_vehicles{};

	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		virtual ~Autoshop();
		void display(std::ostream& out) const;

		// Since this is a template function, it must be implemented in the header!
		// The class is not a template
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) { // adds to the second parameter all vehicles for which the test is true
					vehicles.push_back(*i);
				}
			}
		}
	};
}