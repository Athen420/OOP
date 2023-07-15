// Name:Allan Mathew John
// Seneca Student ID:159852219
// Seneca email:ajohn40@myseneca.ca
// Date of completion:13-07-2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"

namespace sdds
{
    char Utilities::m_delimiter;
    void Utilities::setFieldWidth(size_t newWidth){
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        if (str[next_pos] == m_delimiter) {
            more = false;
            throw("Error: Delimeter at next_pos");
            };

        std::string returnVal;

        //remove space from front (if any)
        while (str[next_pos] == ' ') next_pos++;

        //Read String (end result might contain spaces at back)
        while (next_pos < str.length() && str[next_pos] != m_delimiter) returnVal += str[next_pos++];

        //remove space from back (if any)
        int itr = returnVal.length() - 1;
        while (returnVal[itr] == ' '){
            returnVal.erase(itr, 1);
            itr--;
        }

        //check if there are more values
        if (next_pos == str.length()) more = false;
        else more = true;

        if (m_widthField < returnVal.length()) m_widthField = returnVal.length();

        next_pos++;
        return returnVal;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
} // namespace sdds
