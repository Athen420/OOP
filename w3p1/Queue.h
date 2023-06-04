#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include <iostream>

namespace sdds {
    template <typename T, size_t CAPACITY>
    class Queue {
        T m_queue[CAPACITY]{};
        size_t m_size{};

    public:
        bool push(const T& item);
        T pop();
        size_t size() const;
        void display(std::ostream& os = std::cout) const;
        T operator[](size_t index) const;
    };

    // Specialize the class-member object for type T = Dictionary and CAPACITY = 100u
    template <>
    class Queue<Dictionary, 100u> {
        Dictionary m_queue[100u]{};
        size_t m_size{};

    public:
        bool push(const Dictionary& item) {
            if (m_size < 100u) {
                m_queue[m_size++] = item;
                return true;
            }
            return false;
        }

        Dictionary pop() {
            if (m_size > 0) {
                Dictionary temp = m_queue[0];
                for (size_t i = 0; i < m_size - 1; ++i) {
                    m_queue[i] = m_queue[i + 1];
                }
                --m_size;
                return temp;
            }
            return Dictionary("", ""); // Return an empty Dictionary object if the queue is empty
        }

        size_t size() const {
            return m_size;
        }

        void display(std::ostream& os = std::cout) const {
            for (size_t i = 0; i < m_size; ++i) {
                os << m_queue[i] << '\n';
            }
        }

        Dictionary operator[](size_t index) const {
            if (index < m_size) {
                return m_queue[index];
            }
            return Dictionary("", ""); // Return an empty Dictionary object if the index is out of bounds
        }
    };
}

#endif
