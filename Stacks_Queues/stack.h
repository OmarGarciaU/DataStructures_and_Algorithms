#ifndef STACK
#define STACK
#include <vector>

template<class T, int capacity = 30>
class Stack{
public:
    Stack(){
        pool.reserve(capacity);
    }

    void clear(){
        pool.clear();
    }
    bool isEmpty() const {
        return pool.empty();
    }

    T& topE(){
        return pool.back();
    }

    T pop(){
        T e = pool.back();
        pool.pop_back();
        return e;
    }

    void push(const T& e){
        pool.push_back(e);
    }

private:
    std::vector<T> pool;
};
#endif
