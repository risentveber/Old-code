#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class queue{
    protected:
        int Index;
        int size;
        T* data;
    public:
        void push(const T&);
        bool is_empty() const;
        queue();
        virtual T pop();
        virtual ~queue();
};

#define QUEUE_TPL_H
#include "queue-tpl.h"
#undef QUEUE_TPL_H

#endif //QUEUE_H
