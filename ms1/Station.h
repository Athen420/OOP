// Name:Allan Mathew John
// Seneca Student ID:159852219
// Seneca email:ajohn40@myseneca.ca
// Date of completion:13-07-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
#include <iostream>
namespace sdds
{
    class Station
    {
    private:
        int id = 0;
        std::string name;
        std::string desc;
        unsigned int nextSno = 0;
        unsigned int qty = 0;
        static size_t m_widthField;
        static int id_generator;
    public:
        Station(const std::string str);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
    
} // namespace sdds

#endif