#include "Dictionary.h"

namespace sdds {
    const std::string& Dictionary::getTerm() const {
        return m_term;
    }

    const std::string& Dictionary::getDefinition() const {
        return m_definition;
    }

    Dictionary::Dictionary(const std::string& term, const std::string& definition)
        : m_term(term), m_definition(definition) {
    }

    // Implement the missing functions and operators declared in the header file
    bool Dictionary::operator==(const Dictionary& other) const {
        return m_term == other.m_term;
    }

    bool Dictionary::operator==(const std::string& term) const {
        return m_term == term;
    }

    std::ostream& operator<<(std::ostream& os, const Dictionary& dict) {
        os << dict.m_term << ": " << dict.m_definition;
        return os;
    }
}
