#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>
#include <string>

namespace sdds {
    class Reservation {
        char m_id[8];
        std::string m_name;
        std::string m_email;
        int m_partySize;
        int m_day;
        int m_hour;

    public:
        Reservation();
        Reservation(const std::string& res);
        void update(int day, int time);

        friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
    };
}

#endif // SDDS_RESERVATION_H
