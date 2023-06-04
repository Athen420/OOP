#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include "Dictionary.cpp"  // Include the implementation file for Dictionary class
#include <string>
#include <iostream>

namespace sdds {
class Dictionary {
  std::string m_term{};
  std::string m_definition{};

public:
  const std::string& getTerm() const { return m_term; }
  const std::string& getDefinition() const { return m_definition; }

  Dictionary(const std::string& term, const std::string& definition);

  bool operator==(const Dictionary& other) const;
  bool operator!=(const Dictionary& other) const;
  friend std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary);
};
}

#endif
