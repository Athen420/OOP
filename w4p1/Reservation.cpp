#include "Reservation.h"
#include <cstring>

namespace sdds {
    Reservation::Reservation() {
        m_id[0] = '\0';
        m_name = "";
        m_email = "";
        m_partySize = 0;
        m_day = 0;
        m_hour = 0;
    }

    Reservation::Reservation(const std::string& res) {
        std::string temp = res;
        size_t startPos = temp.find(':');
        size_t endPos = temp.find(',', startPos);

        // Extracting reservation ID
        std::string id = temp.substr(startPos + 1, endPos - startPos - 1);
        m_id[0] = '\0';
        if (!id.empty()) {
            size_t idStart = id.find_first_not_of(' ');
            size_t idEnd = id.find_last_not_of(' ');
            if (idStart != std::string::npos && idEnd != std::string::npos)
                id = id.substr(idStart, idEnd - idStart + 1);
            if (id.length() <= 10)
                std::strncpy(m_id, id.c_str(), sizeof(m_id));
            else
                std::strncpy(m_id, id.substr(0, 10).c_str(), sizeof(m_id) - 1);
            m_id[sizeof(m_id) - 1] = '\0';
        }

        // Extracting name
        startPos = endPos;
        endPos = temp.find(',', startPos + 1);
        m_name = temp.substr(startPos + 1, endPos - startPos - 1);
        m_name.erase(0, m_name.find_first_not_of(' '));
        m_name.erase(m_name.find_last_not_of(' ') + 1);

        // Extracting email
        startPos = endPos;
        endPos = temp.find(',', startPos + 1);
        m_email = temp.substr(startPos + 1, endPos - startPos - 1);
        m_email.erase(0, m_email.find_first_not_of(' '));
        m_email.erase(m_email.find_last_not_of(' ') + 1);

        // Extracting party size
        startPos = endPos;
        endPos = temp.find(',', startPos + 1);
        m_partySize = std::stoi(temp.substr(startPos + 1, endPos - startPos - 1));

        // Extracting day
        startPos = endPos;
        endPos = temp.find(',', startPos + 1);
        m_day = std::stoi(temp.substr(startPos + 1, endPos - startPos - 1));

        // Extracting hour
        startPos = endPos;
        endPos = temp.length();
        m_hour = std::stoi(temp.substr(startPos + 1, endPos - startPos - 1));
    }

    void Reservation::update(int day, int time) {
        m_day = day;
        m_hour = time;
    }

    std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
        std::string mealType;
        if (reservation.m_hour >= 6 && reservation.m_hour <= 9)
            mealType = "Breakfast";
        else if (reservation.m_hour >= 11 && reservation.m_hour <= 15)
            mealType = "Lunch";
        else if (reservation.m_hour >= 17 && reservation.m_hour <= 21)
            mealType = "Dinner";
        else
            mealType = "Drinks";

        os << "Reservation " << reservation.m_id << ":";
        os.width(20);
        os << std::right << reservation.m_name;
        os << "  <" << std::left << reservation.m_email << ">    ";
        os << mealType << " on day " << reservation.m_day << " @ " << reservation.m_hour << ":00";
        os << " for " << reservation.m_partySize;
        if (reservation.m_partySize == 1)
            os << " person.";
        else
            os << " people.";
        os << std::endl;

        return os;
    }
}
