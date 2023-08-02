#include "Racecar.h"
#include "Utilities.h"
using namespace std;

namespace sdds {
	Racecar::Racecar(std::istream& in):Car::Car(in) {
		string tempBooster{};

		getline(in, tempBooster, ',');
		m_booster = stod(trim(tempBooster));
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);

		out << "*";
	}

	double Racecar::topSpeed() const {
		double boostSpeed = Car::topSpeed() * (1 + m_booster);
		return boostSpeed;
	}

	bool Racecar::booster() const {
		bool result = true;

		if (m_booster == 0.00) {
			result = false;
		}

		return result;
	}
}