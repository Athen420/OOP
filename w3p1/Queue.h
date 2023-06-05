#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include <iostream>
#include <iomanip>
#include "Dictionary.h"

namespace sdds {
    template <typename T, unsigned int CAPACITY>
    class Queue {
        T m_array[CAPACITY]{};
        unsigned int m_size{};

    public:
        bool push(const T& item) {
            if (m_size < CAPACITY) {
                m_array[m_size++] = item;
                return true;
            }
            return false;
        }

        T pop() {
            if (m_size > 0) {
                T item = m_array[0];
                for (unsigned int i = 1; i < m_size; i++) {
                    m_array[i - 1] = m_array[i];
                }
                m_size--;
                return item;
            }
            return T();
        }

        unsigned int size() const {
            return m_size;
        }

       void display(std::ostream& os = std::cout) const {
            os <<  "----------------------" << std::endl;
            os <<  "| Dictionary Content |" << std::endl;
            os <<  "----------------------" << std::endl;
	    for (unsigned int i = 0; i < m_size; i++) {
                os << m_array[i] << "\n";
            }
            os <<  "----------------------" << std::endl;
        }

        const T& operator[](unsigned int index) const {
            return m_array[index];
        }
    };

    template<>
    class Queue<Dictionary, 50> {
        Dictionary m_array[50]{};
        unsigned int m_size{};

    public:
        bool push(const Dictionary& item) {
            if (m_size < 50) {
                m_array[m_size++] = item;
                return true;
            }
            return false;
        }

        Dictionary pop() {
            if (m_size > 0) {
                Dictionary item = m_array[0];
                for (unsigned int i = 1; i < m_size; i++) {
                    m_array[i - 1] = m_array[i];
                }
                m_size--;
                return item;
            }
            return Dictionary();
        }

        unsigned int size() const {
            return m_size;
        }

        void display(std::ostream& os = std::cout) const {
            os <<  "----------------------" << std::endl;
            os <<  "| Dictionary Content |" << std::endl;
            os <<  "----------------------" << std::endl;
            for (unsigned int i = 0; i < m_size; i++) {
                os << std::setw(20) << m_array[i].getTerm() << ": " << m_array[i].getDefinition() << std::endl;
            }
            os <<  "----------------------" << std::endl;
        }

        const Dictionary& operator[](unsigned int index) const {
            return m_array[index];
        }
    };
}

#endif
