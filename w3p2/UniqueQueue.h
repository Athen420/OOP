#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include <iostream>
#include <cmath>

namespace sdds {
    template<typename T>
    class UniqueQueue : public Queue<T, 100> {
    public:
        bool push(const T& item) {
            if (!contains(item)) {
                return Queue<T, 100>::push(item);
            }
            return false; // Item already exists, don't add it
        }

    private:
        bool contains(const T& item) const {
            for (unsigned int i = 0; i < this->size(); i++) {
                if (isEqual(item, this->operator[](i))) {
                    return true;
                }
            }
            return false;
        }

        bool isEqual(const T& item1, const T& item2) const {
            if constexpr (std::is_same_v<T, double>) {
                return (std::fabs(item1 - item2) <= 0.005);
            }
            else {
                return (item1 == item2);
            }
        }
    };
}

#endif