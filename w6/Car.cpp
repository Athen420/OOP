#include "Car.h"
#include "Utilities.h"
using namespace std;

namespace sdds {
	Car::Car() {}

	Car::Car(istream& input) {
		string  tempMaker{}, tempCondition{}, tempSpeed{};

		getline(input, tempMaker, ',');
		getline(input, tempCondition, ',');
		getline(input, tempSpeed, ',');

		m_maker = trim(tempMaker);
		m_condition = trim(tempCondition);
		m_condition = condition();

		if (m_condition[0] != 'n' && m_condition[0] != 'u' && m_condition[0] != 'b') {
			throw 1;
		}

		try {
			m_topSpeed = stod(trim(tempSpeed));
		}
		catch (const std::exception&) {
			throw 1;
		}
	}

	std::string Car::condition() const {
		string result{};

		if (m_condition[0] == 'n' || m_condition.empty()) {
			result = "new";
		}
		else if (m_condition[0] == 'u') {
			result = "used";
		}
		else if (m_condition[0] == 'b') {
			result = "broken";
		}

		return result;
	}

	double Car::topSpeed() const {
		return static_cast<double>(m_topSpeed);
	}

	void Car::display(std::ostream& out) const {
		out << "| ";
		out << std::right << std::setw(10) << m_maker;
		out << " | ";
		out << std::left << std::setw(6) << m_condition;
		out << " | ";
		out << std::right << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed();
		out << " |";
	}
}