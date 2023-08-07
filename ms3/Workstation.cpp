#include "Workstation.h"

namespace sdds
{
    std::deque<CustomerOrder> g_completed;
    std::deque<CustomerOrder> g_pending;
    std::deque<CustomerOrder> g_incomplete;

    void Workstation::fill(std::ostream& os) {
        if (m_orders.size() <= 0) return;
        m_orders.front().fillItem(*this, os);
    }

    bool Workstation::attemptToMoveOrder() {
        if (m_orders.size() == 0) return false;
        if (!(m_orders.front().isItemFilled(Station::getItemName())) && Station::getQuantity() > 0 ) return false;

        if (m_pNextStation == nullptr) {
            if (m_orders.front().isOrderFilled()){
                g_completed.push_back(std::move(m_orders.front()));
            }
            else {
                g_incomplete.push_back(std::move(m_orders.front()));
            }
        }
        else {
            m_pNextStation->m_orders.push_back(std::move(m_orders.front()));
        }
        m_orders.pop_front();

        return true;
    }

    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const {
        os << Station::getItemName() << " --> ";
        if (m_pNextStation == nullptr) os << "End of Line";
        else os << m_pNextStation->getItemName();
        os << std::endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
} // namespace sdds
