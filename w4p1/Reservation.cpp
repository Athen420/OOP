#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "Reservation.h"

namespace sdds {
    Reservation::Reservation() : m_id{}, m_name{}, m_email{}, m_partySize{ 0 }, m_day{ 0 }, m_hour{ 0 } {}

    Reservation::Reservation(const std::string& res) : Reservation() {
        std::istringstream iss(res);
        std::string token;

        std::getline(iss, token, ':');
        std::strncpy(m_id, token.c_str(), sizeof(m_id) - 1);
        m_id[sizeof(m_id) - 1] = '\0';

        std::getline(iss, token, ',');
        m_name = token;
        m_name.erase(0, m_name.find_first_not_of(' '));
        m_name.erase(m_name.find_last_not_of(' ') + 1);

        std::getline(iss, token, ',');
        m_email = token;
        m_email.erase(0, m_email.find_first_not_of(' '));
        m_email.erase(m_email.find_last_not_of(' ') + 1);

        std::getline(iss, token, ',');
        m_partySize = std::stoi(token);

        std::getline(iss, token, ',');
        m_day = std::stoi(token);

        std::getline(iss, token);
        m_hour = std::stoi(token);
    }

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
        os << "Reservation ID: " << std::setw(10) << std::right << reservation.m_id
            << "  <" << std::setw(20) << std::left << reservation.m_email << ">";

        if (reservation.m_hour >= 6 && reservation.m_hour <= 9) {
            os << "    Breakfast on day " << std::setw(2) << reservation.m_day
                << " @ " << std::setw(2) << reservation.m_hour << ":00 for "
                << std::setw(2) << reservation.m_partySize << " " << (reservation.m_partySize == 1 ? "person." : "people.");
        }
        else if (reservation.m_hour >= 11 && reservation.m_hour <= 15) {
            os << "    Lunch on day " << std::setw(2) << reservation.m_day
                << " @ " << std::setw(2) << reservation.m_hour << ":00 for "
                << std::setw(2) << reservation.m_partySize << " " << (reservation.m_partySize == 1 ? "person." : "people.");
        }
        else if (reservation.m_hour >= 17 && reservation.m_hour <= 21) {
            os << "    Dinner on day " << std::setw(2) << reservation.m_day
                << " @ " << std::setw(2) << reservation.m_hour << ":00 for "
                << std::setw(2) << reservation.m_partySize << " " << (reservation.m_partySize == 1 ? "person." : "people.");
        }
        else {
            os << "    Drinks on day " << std::setw(2) << reservation.m_day
                << " @ " << std::setw(2) << reservation.m_hour << ":00 for "
                << std::setw(2) << reservation.m_partySize << " " << (reservation.m_partySize == 1 ? "person." : "people.");
        }

        os << std::endl;
        return os;
    }
}
