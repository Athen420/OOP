#include "Autoshop.h"

using namespace std;

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);

		return *this;
	}

	Autoshop::~Autoshop() {
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			delete *i;
		}
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		// STL iterator
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(out);
			out << endl;
		}


		out << "--------------------------------" << endl;
	}
}