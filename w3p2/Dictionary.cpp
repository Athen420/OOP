#include "Dictionary.h"

namespace sdds {
    const std::string& Dictionary::getTerm() const {
        return m_word;
    }

    const std::string& Dictionary::getDefinition() const {
        return m_def;
    }

    Dictionary::Dictionary(const std::string& word, const std::string& def)
        : m_word(word), m_def(def) {
    }
}
