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
        Dictionary(const std::string& term = "", const std::string& definition = "");
    };
}
#endif // SDDS_DICTIONARY_H
