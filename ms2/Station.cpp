// Name:Allan Mathew John
// Seneca Student ID:159852219
// Seneca email:ajohn40@myseneca.ca
// Date of completion:13-07-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Station.h"
#include "Utilities.h"
#include <iomanip>

namespace sdds {
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station(const std::string str) {
        Utilities util;
        size_t next_pos = 0;
        id = ++id_generator;
        bool more;

        name = util.extractToken(str, next_pos, more);
        if (more) nextSno = std::stoi(util.extractToken(str, next_pos, more));
        if (more) qty = std::stoi(util.extractToken(str, next_pos, more));

        if (m_widthField < util.getFieldWidth())
            m_widthField = util.getFieldWidth();

        if (more) desc = util.extractToken(str, next_pos, more);
    }

    const std::string& Station::getItemName() const {
        return name;
    }

    size_t Station::getNextSerialNumber() {
        return nextSno++;
    }

    size_t Station::getQuantity() const {
        return qty;
    }

    void Station::updateQuantity() {
        if (qty > 0)
            qty--;
    }

    void Station::display(std::ostream& os, bool full) const {
        os << std::setw(3) << std::setfill('0') << std::right << id << " | "
           << std::setw(m_widthField) << std::setfill(' ') << std::left << name << " | "
           << std::setw(6) << std::setfill('0') << std::right << nextSno << " | ";

        if (full) {
            os << std::setw(4) << std::setfill(' ') << std::right << qty << " | "
               << desc;
        }

        os << std::endl;
    }
}  // namespace sdds
