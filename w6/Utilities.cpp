#include "Utilities.h"
using namespace std;

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Car* tempC{};
		Racecar* tempR{};
		stringstream ss;
		string tempTag{}, tempLine{};

		getline(in, tempLine);
		ss << tempLine;

		getline(ss, tempTag, ','); // c or C otherwise invalid
		tempTag = trim(tempTag);
		if (tempTag.empty()) {
			return nullptr;
		}
		else if (tempTag[0] == 'c' || tempTag[0] == 'C') {
			return tempC = new Car(ss);
		}
		else if (tempTag[0] == 'r' || tempTag[0] == 'R') {
			return tempR = new Racecar(ss);
		}
		else {
			throw tempTag[0];
		}
	}

	std::string trim(std::string input) {
		size_t startPos{};
		size_t endPos{};
		string result{};
		bool checkSpace{};

		for (size_t i = 0; i < input.length(); i++) {
			if (input[i] == ' ') {
				checkSpace = false;
			}
			else {
				checkSpace = true;
				break;
			}
		}

		if (!input.empty() && checkSpace) { // **should fix to handle empty and space
			startPos = input.find_first_not_of(" "); // find the position of first letter
			endPos = input.find_last_not_of(" "); // find the position of last letter
			result = input.substr(startPos, endPos - startPos + 1); // trim spaces in front of, behind of the word
		}

		return result;
	}
}