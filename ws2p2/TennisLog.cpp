#include "TennisLog.h"
#include <iomanip>
#include <fstream>

namespace sdds
{
    // Overloaded insertion operator for TennisMatch objects
    std::ostream& operator<<(std::ostream& os, const TennisMatch& match) {
        if (match.matchID == -1) {
            os << "Empty Match";
            return os;
        }

        os << std::setw(20) << std::setfill('.') << std::right << "Tourney ID" << " : "
           << std::setw(30) << std::setfill('.') << std::left << match.tournamentID << std::endl;

        os << std::setw(20) << std::setfill('.') << std::right << "Match ID" << " : "
           << std::setw(30) << std::setfill('.') << std::left << match.matchID << std::endl;

        os << std::setw(20) << std::setfill('.') << std::right << "Tourney" << " : "
           << std::setw(30) << std::setfill('.') << std::left << match.tournamentName << std::endl;

        os << std::setw(20) << std::setfill('.') << std::right << "Winner" << " : "
           << std::setw(30) << std::setfill('.') << std::left << match.winner << std::endl;

        os << std::setw(20) << std::setfill('.') << std::right << "Loser" << " : "
           << std::setw(30) << std::setfill('.') << std::left << match.loser << std::endl;
        os << std::setfill(' ');
        return os;
    }

    // Default constructor
    TennisLog::TennisLog() {}

    // Copy constructor
    TennisLog::TennisLog(const TennisLog& other) {
        *this = other;
    }

    // Move constructor
    TennisLog::TennisLog(TennisLog&& other) {
        *this = std::move(other);
    }

    // Copy assignment operator
    TennisLog& TennisLog::operator=(const TennisLog& other) {
        // Delete existing matches
        for (size_t i = 0; i < count; i++) {
            delete matches[i];
        }
        delete[] matches;
        matches = nullptr;
        count = 0;

        if (other.matches == nullptr) return *this;

        // Copy matches from other
        matches = new TennisMatch*[other.count];
        count = other.count;
        for (size_t i = 0; i < count; i++) {
            matches[i] = new TennisMatch(*other.matches[i]);
        }
        return *this;
    }

    // Move assignment operator
    TennisLog& TennisLog::operator=(TennisLog&& other) {
        // Delete existing matches
        for (size_t i = 0; i < count; i++) {
            delete matches[i];
        }
        delete[] matches;

        // Move matches from other
        matches = other.matches;
        count = other.count;
        other.matches = nullptr;
        other.count = 0;
        return *this;
    }

    // Constructor with file input
    TennisLog::TennisLog(std::string filename) {
        std::ifstream file(filename);
        if (!file) return;

        std::string temp;
        int numMatches = 0;

        // Count the number of matches in the file
        std::getline(file, temp);
        while (file.peek() != EOF) {
            std::getline(file, temp);
            numMatches++;
        }
        file.clear();
        file.seekg(0);

        // Allocate memory for matches
        matches = new TennisMatch*[numMatches];
        count = numMatches;

        // Read match data from the file and create TennisMatch objects
        std::getline(file, temp);
        for (int i = 0; i < numMatches; i++) {
            matches[i] = new TennisMatch();

            std::getline(file, matches[i]->tournamentID, ',');
            std::getline(file, matches[i]->tournamentName, ',');
            file >> matches[i]->matchID;
            file.ignore(1);
            std::getline(file, matches[i]->winner, ',');
            std::getline(file, matches[i]->loser);
        }
    }

    // Destructor
    TennisLog::~TennisLog() {
        for (size_t i = 0; i < count; i++) {
            delete matches[i];
        }
        delete[] matches;
    }

    // Add a match to the log
    void TennisLog::addMatch(TennisMatch& match) {
        TennisMatch** matchArray = new TennisMatch*[count + 1];

        // Copy existing matches to the new array
        for (size_t i = 0; i < count; i++) {
            matchArray[i] = matches[i];
        }

        delete[] matches;
        matchArray[count++] = new TennisMatch(match);
        matches = matchArray;
    }

    // Find matches involving a specific player
    TennisLog TennisLog::findMatches(std::string player) const {
        TennisLog result;
        for (size_t i = 0; i < count; i++) {
            if (matches[i]->winner == player || matches[i]->loser == player) {
                result.addMatch(*matches[i]);
            }
        }
        return result;
    }

    // Index operator
    TennisMatch TennisLog::operator[](size_t idx) const {
        TennisMatch result;
        if (idx < 0 || idx >= count) return result;

        result = *matches[idx];
        return result;
    }

    // Conversion operator to size_t
    TennisLog::operator size_t() const {
        return count;
    }
} // namespace sdds
