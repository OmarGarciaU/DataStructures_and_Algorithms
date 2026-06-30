// Linked List Stack

#ifndef LL_STACK
#define LL_STACK

#include <list>

template<class T>

class LLStack{
public:
    LLStack(){
    }

    void clear(){
        lst.clear();
    }

    bool isEmpty() const {
        return lst.empty();
    }

    T& topE(){
        return lst.back();
    }

    T pop(){
        T e = lst.back();
        lst.pop_back();
        return e;
    }
    void push(const T& e){
        lst.push_back(e);
    }

private:
    std::list<T> lst;
};

#endif
