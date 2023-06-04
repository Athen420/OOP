#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include <iostream>

namespace sdds {
	template <typename T, int N>
	class Queue {
		T m_array[N];
		int m_front{ 0 };
		int m_back{ 0 };
		int m_size{ 0 };
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
