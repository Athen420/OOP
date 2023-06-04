#include "UniqueQueue.h"

namespace sdds {

template <typename T>
bool UniqueQueue<T>::isDuplicate(const T& item) const {
  for (unsigned int i = 0; i < this->m_size; ++i) {
    if (item == this->m_array[i]) {
      return true;
    }
  }
  return false;
}

template <typename T>
bool UniqueQueue<T>::push(const T& item) {
  if (!isDuplicate(item)) {
    return Queue<T, 100>::push(item);
  }
  return false;
}

// Explicit instantiations for UniqueQueue class template
template class UniqueQueue<int>;
template class UniqueQueue<float>;
template class UniqueQueue<Dictionary>;

}  // namespace sdds
