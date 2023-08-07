// Name:Allan Mathew John
// Seneca Student ID:159852219
// Seneca email:ajohn40@myseneca.ca
// Date of completion:21-07-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "CustomerOrder.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>

namespace sdds
{
    size_t CustomerOrder::m_widthField;
    void CustomerOrder::addItem(std::string str) {
        // Making new array of Items(1 size bigger) and copying all previous values
        Item** newList = new Item*[m_cntItem + 1];
        for (size_t i = 0; i < m_cntItem; i++)
        {
            newList[i] = m_lstItem[i];
        }
        // Adding the new item
        Item* item = new Item(str);
        newList[m_cntItem++] = item;
        
        delete[] m_lstItem;
        m_lstItem = newList;
    }

    CustomerOrder::CustomerOrder(const std::string str) {
        Utilities ut;
        bool isMore = true;
        size_t nextPos = 0;
        try{
            m_name = ut.extractToken(str, nextPos, isMore);
        } catch (const std::string& e) {
            std::cout << e;
        }

        if (isMore){
            try {
                m_product = ut.extractToken(str, nextPos, isMore);
            } catch (const std::string& e) {
                std::cout << e;
            }
        }

        if (isMore) {
            while (isMore) addItem(ut.extractToken(str, nextPos, isMore));
        }

        if (ut.getFieldWidth() > m_widthField) m_widthField = ut.getFieldWidth();
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
        *this = std::move(other);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) noexcept {
        if (this != &other) {
            m_name = other.m_name;
            m_product = other.m_product;
            m_widthField = other.m_widthField;
            //Delete our list
            for(size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
            delete [] m_lstItem;

            //Steal for other :)
            m_cntItem = other.m_cntItem;
            m_lstItem = other.m_lstItem;
            other.m_lstItem = nullptr;
            other.m_cntItem = 0;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        for(size_t i = 0; i < m_cntItem; i++) delete m_lstItem[i];
        delete [] m_lstItem;
    }

    bool CustomerOrder::isOrderFilled() const {
        for(size_t i = 0; i < m_cntItem; i++){
            if (m_lstItem[i]->m_isFilled == false) return false;
        }
        return true;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        for (size_t i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == itemName) return m_lstItem[i]->m_isFilled;
        }
        return true;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        for(size_t i = 0; i < m_cntItem; i++){
            if (m_lstItem[i]->m_itemName == station.getItemName()){
                if (station.getQuantity() > 0) {
                    station.updateQuantity();
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName <<"]" << std::endl;
                    break;
                }
                else {
                    os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName <<"]" << std::endl;
                    break;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            // [SERIAL] ITEM_NAME - STATUS;
            os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - ";
            if (m_lstItem[i]->m_isFilled) os << "FILLED";
            else os << "TO BE FILLED";
            os << std::endl;
        }
    }
} // namespace sdds
