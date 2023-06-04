#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "UniqueQueue.cpp"  // Include the implementation file for UniqueQueue class
#include "Queue.h"
#include <cmath>

namespace sdds{

template <typename T>
class UniqueQueue : public Queue<T, 100> {
  bool isDuplicate(const T& item) const;

public:
  bool push(const T& item) override;
};
}

#endif
