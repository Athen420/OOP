#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
    class Workstation : public Station
    {
    private:
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation = nullptr;
    public:
        Workstation(const std::string str) : Station(str) {};
        Workstation(const Workstation& other) = delete;
        Workstation& operator=(const Workstation& other) = delete;
        Workstation(Workstation&& other) = delete;
        Workstation& operator=(Workstation&& other) = delete;

        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };

    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

} // namespace sdds

#endif
