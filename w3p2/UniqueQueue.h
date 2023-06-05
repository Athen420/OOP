#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <cmath>
#include "Queue.h"

namespace sdds {
    template<typename T>
    class UniqueQueue : public Queue<T, 100u> {
        public:
           bool push(const T& item);
    };

    template<typename T>
    bool UniqueQueue<T>::push(const T& item){
        for (unsigned int i = 0; i < this->size(); i++){
            if (this->operator[](i) == item) return false;
        }

        return Queue<T, 100u>::push(item);
    }

    template<>
    bool UniqueQueue<double>::push(const double& item){
        for (unsigned int i = 0; i < this->size(); i++){
            if (std::fabs(this->operator[](i) - item) <= 0.005) return false;
        }

        return Queue<double, 100u>::push(item);
    }
}
#endif
