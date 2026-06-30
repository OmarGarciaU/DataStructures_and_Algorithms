#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>

template<class T>
class Queue{
public:
    Queue(){
    }
    void clear(){
        lst.clear();
    }

    bool isEmpty() const {
        return lst.empty();
    }

    T& front(){
        return lst.front();
    }

    T dequeue(){
        T e = lst.front();
        lst.pop_front();
        return e;
    }

    void enqueue(const T& e){
        lst.push_back(e);
    }

private:
    std::list<T> lst;
};

#endif
