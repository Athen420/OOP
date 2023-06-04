#include "Dictionary.h"

namespace sdds {

Dictionary::Dictionary(const std::string& term, const std::string& definition)
    : m_term(term), m_definition(definition) {}

bool Dictionary::operator==(const Dictionary& other) const {
  return m_term == other.m_term;
}

bool Dictionary::operator!=(const Dictionary& other) const {
  return m_term != other.m_term;
}

std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary) {
  os << dictionary.m_term << ": " << dictionary.m_definition;
  return os;
}

}  // namespace sdds
