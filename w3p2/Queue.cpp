#include "Queue.h"

namespace sdds {

template <typename T, unsigned int CAPACITY>
Queue<T, CAPACITY>::Queue() : m_size(0) {}

template <typename T, unsigned int CAPACITY>
bool Queue<T, CAPACITY>::push(const T& item) {
  if (m_size < CAPACITY) {
    m_array[m_size++] = item;
    return true;
  }
  return false;
}

template <typename T, unsigned int CAPACITY>
T Queue<T, CAPACITY>::pop() {
  if (m_size > 0) {
    T temp = m_array[0];
    for (unsigned int i = 0; i < m_size - 1; ++i) {
      m_array[i] = m_array[i + 1];
    }
    --m_size;
    return temp;
  }
  return T();  // Return a default-constructed object if queue is empty
}

template <typename T, unsigned int CAPACITY>
unsigned int Queue<T, CAPACITY>::size() const {
  return m_size;
}

template <typename T, unsigned int CAPACITY>
void Queue<T, CAPACITY>::display(std::ostream& os) const {
  for (unsigned int i = 0; i < m_size; ++i) {
    os << "Item [" << i << "]: " << m_array[i] << std::endl;
  }
}

template <typename T, unsigned int CAPACITY>
T Queue<T, CAPACITY>::operator[](unsigned int index) const {
  if (index < m_size) {
    return m_array[index];
  }
  return T();  // Return a default-constructed object if index is out of bounds
}

// Explicit instantiations for Queue class template
template class Queue<int, 100>;
template class Queue<float, 100>;
template class Queue<Dictionary, 100>;

}  // namespace sdds
