#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<class T>
class DLLNode{
public:
    DLLNode(){
        next = prev = nullptr;
    }
    DLLNode(const T& e, DLLNode *n = 0, DLLNode *p = 0){
        info = e;
        next = n;
        prev = p;
    }
    T info;
    DLLNode *next, *prev;
};

template<class T>
class DLL {
public:
    DLL(){
        head = tail = 0;
    }
    void addToTail(const T&);
    T deleteFromTail();

protected:
    DLLNode<T> *head, *tail;
};
#endif 

#include <iostream>


template<class T>
void DLL<T>::addToTail(const T& e){
    if(tail != 0){
        tail = new DLLNode<T>(e, 0, tail);
        tail->prev->next = tail;
    }else head = tail = new DLLNode<T>(e);
}

template<class T>
T DLL<T>::deleteFromTail(){
    T e = tail->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    }else{
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }

    return e;
}

int main(){
    DLL<int> list;
    list.addToTail(5);
}
