#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include "Dictionary.h"
#include <iostream>

namespace sdds {
    template<typename T, unsigned int CAPACITY>
    class Queue {
        private:
            T m_array[CAPACITY] = {};
            unsigned int m_size = 0;
            static T m_defaultVal;
        public:
            virtual bool push(const T& item);
            T pop();
            unsigned int size() const;
            void display(std::ostream& os = std::cout) const;
            T operator[](unsigned int index) const;
            virtual ~Queue() {};
    };

    template<typename T, unsigned int CAPACITY>
    T Queue<T, CAPACITY>::m_defaultVal = {};

    template<>
    Dictionary Queue<Dictionary, 100u>::m_defaultVal = Dictionary("Empty Term", "Empty Substitute");

    template<typename T, unsigned int CAPACITY>
    bool Queue<T, CAPACITY>::push(const T& item) {
        if (m_size < CAPACITY) {
            m_array[m_size++] = item;
            return true;
        }
        return false;
    }

    template<typename T, unsigned int CAPACITY>
    T Queue<T, CAPACITY>::pop() {
        if (m_size > 0) {
            T targetObj = m_array[0];
            for (unsigned int i = 1; i < m_size; i++) {
                m_array[i - 1] = m_array[i];
            }
            m_size--;
            return targetObj;
        }
        return m_defaultVal;
    }

    template<typename T, unsigned int CAPACITY>
    unsigned int Queue<T, CAPACITY>::size() const {
        return m_size;
    }

    template<typename T, unsigned int CAPACITY>
    void Queue<T, CAPACITY>::display(std::ostream& os) const {
        os << "----------------------" << std::endl;
        os << "| Dictionary Content |" << std::endl;
        os << "----------------------" << std::endl;

        for (unsigned int i = 0; i < m_size; i++) {
            os << m_array[i] << std::endl;
        }
        os << "----------------------" << std::endl;
    }

    template<typename T, unsigned int CAPACITY>
    T Queue<T, CAPACITY>::operator[](unsigned int index) const {
        if (index >= m_size) return m_defaultVal;
        return m_array[index];
    }
}

#endif
