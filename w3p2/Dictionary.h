#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include <string>

namespace sdds {
    class Dictionary {
        std::string m_word;
        std::string m_def;

    public:
        Dictionary();
        Dictionary(const std::string& word, const std::string& def);
        const std::string& getTerm() const;
        const std::string& getDefinition() const;
    };
}

#endif // SDDS_DICTIONARY_H
