#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H

#include <string>

namespace sdds {
    class Dictionary {
        std::string m_term{};
        std::string m_definition{};

    public:
        const std::string& getTerm() const;
        const std::string& getDefinition() const;
        Dictionary(const std::string& term, const std::string& definition);

        // Declare the missing prototype functions and operators needed to work with the Queue class
        bool operator==(const Dictionary& other) const;
        bool operator==(const std::string& term) const;
        friend std::ostream& operator<<(std::ostream& os, const Dictionary& dict);
    };
}

#endif
