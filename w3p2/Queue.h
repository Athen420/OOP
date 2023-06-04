#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include "Queue.cpp"  // Include the implementation file for Queue class

#include <iostream>

namespace sdds{

template <typename T, unsigned int CAPACITY>
class Queue {
  T m_array[CAPACITY]{};
  unsigned int m_size{};

public:
  Queue();

  bool push(const T& item);
  T pop();
  unsigned int size() const;
  void display(std::ostream& os = std::cout) const;
  T operator[](unsigned int index) const;
};
}

#endif
