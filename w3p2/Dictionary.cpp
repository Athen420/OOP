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
}
