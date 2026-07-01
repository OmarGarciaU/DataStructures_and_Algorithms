/*
 * Omar Garcia 2026
 * Linked List implementation of Breath First Search 
 * */


#include <iostream>

#ifndef LL_BFS
#define LL_BFS

template<class T>
class LinkedListBreathFirstSearchNode{
public:
    LinkedListBreathFirstSearchNode(){
        next = nullptr;
    }

    LinkedListBreathFirstSearchNode(T e, LinkedListBreathFirstSearchNode<T> *p){
        info = e;
        next = p;
    }

    T info;
    LinkedListBreathFirstSearchNode<T> *next;
};

template<class T>
class LinkedListBreathFirstSearch{
public:
    LinkedListBreathFirstSearch(){
        head = tail = nullptr;
        size = 0;
        LinkedListBreathFirstSearchNode<T> *tmp;
        for(tmp = head; tmp != nullptr; tmp = tmp->next) size++;
    }

    ~LinkedListBreathFirstSearch();
    bool isEmpty(){return head == nullptr;}
    void addToHead(T e);
    void addToTial(T e);
    T deleteFromHead();
    T deleteFromTail();
    void deleteNode(T e);
    bool isInList(T e) const;
    void printList();
    int getSize() const;


private:
    LinkedListBreathFirstSearchNode<T> *head, *tail;
    int size;
};

#endif

template<class T>
LinkedListBreathFirstSearch<T>::~LinkedListBreathFirstSearch(){
    for(LinkedListBreathFirstSearchNode<T> *p; !isEmpty();) {
        p = head -> next;
        delete head;
        head = p;
    }
}

template<class T>
void LinkedListBreathFirstSearch<T>::addToHead(T e){
    head = new LinkedListBreathFirstSearchNode<T>(e, head);
    if(tail == 0) {
        tail = head;
    }
    size++;
}

template<class T>
void LinkedListBreathFirstSearch<T>::addToTial(T e){
    if(tail != nullptr){
        tail->next = new LinkedListBreathFirstSearchNode<T>(e,tail->next);
        tail = tail->next;
    }else {
        head = tail = new LinkedListBreathFirstSearchNode<T>(e, tail->next);
    }
    size++;
}

template<class T>
T LinkedListBreathFirstSearch<T>::deleteFromHead(){
    T e = head->info; 
    LinkedListBreathFirstSearchNode<T> *tmp = head;
    if(head == tail) head = tail = nullptr;
    else head = head->next;
    delete tmp;
    size--;
    return e;
}

template<class T>
T LinkedListBreathFirstSearch<T>::deleteFromTail(){
    T e = tail->info;
    if(head == tail) {
        delete head;
        head = tail = nullptr;
        size--;
    }else{
        LinkedListBreathFirstSearchNode<T> *tmp;
        for(tmp = head; tmp->next != tail; tmp = tmp ->next); // traverse the list starting from head til you get to tail
        delete tail;
        tail = tmp;
        tail->next = nullptr;
        size--;
    }
    return e;
}

template<class T>
void LinkedListBreathFirstSearch<T>::deleteNode(T e){
    if(head != nullptr){
        if(head == tail && e == head->info){ // if there's only one element and e is the first element
            delete head;
            head = tail = nullptr;
            size--;
        }else if(e == head->info){ // if e is only the first element
            LinkedListBreathFirstSearchNode<T> *tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }else{
            LinkedListBreathFirstSearchNode<T> *pred, *tmp;
            for(pred=head, tmp = head->next; tmp != 0 && !(tmp->info == e);pred = pred->next, tmp = tmp->next);
            if(tmp != 0){
                pred->next = tmp->next;
                if(tmp == tail) tail = pred;
                delete tmp;
                size--;
            }
        }
    }

}

template<class T>
bool LinkedListBreathFirstSearch<T>::isInList(T e) const {
    LinkedListBreathFirstSearchNode<T> *tmp;
    for(tmp = head; tmp!= 0 && !(tmp->info == e); tmp=tmp->next);
    return tmp != 0;
}

template<class T>
void LinkedListBreathFirstSearch<T>::printList(){
    // if list is Empty
    if(isEmpty()) std::cout << "List is empty" << std::endl;
    else {
        LinkedListBreathFirstSearchNode<T> *tmp;
        for(tmp = head; tmp != nullptr; tmp = tmp->next){
            std::cout << tmp->info << std::endl;
        }
    }
}

template<class T>
int LinkedListBreathFirstSearch<T>::getSize() const {
    return size;
}

int main(){
    LinkedListBreathFirstSearch<int> list;
    list.addToHead(45);
    list.addToTial(90);
    list.printList();
    std::cout << list.getSize() << std::endl;
}
