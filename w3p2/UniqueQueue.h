#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "Queue.h"

namespace sdds {
	template <typename T>
	class UniqueQueue : public Queue<T, 100> {
	public:
        bool push(const T& item) override;
    };
}

#endif
