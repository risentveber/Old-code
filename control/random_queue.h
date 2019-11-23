#ifndef RANDOM_QUEUE_H
#define RANDOM_QUEUE_H
#include "queue.h"

template<typename T>
class random_queue : public queue<T>{
    public:
        T pop();
        random_queue();
        ~random_queue();
};

#define RANDOM_QUEUE_TPL_H
#include "random_queue-tpl.h"
#undef RANDOM_QUEUE_TPL_H

#endif //RANDOM_QUEUE_H

