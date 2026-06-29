#ifndef INT_SLL
#define INT_SLL
class IntSLLNode{
public:
    IntSLLNode(){
        //next node points to nothing
        next = 0;
    }

    IntSLLNode(int e, IntSLLNode *ptr = 0){
        info = e;
        next = ptr;
    }

    int info;
    IntSLLNode *next;
};

class IntSLL{
public:
    IntSLL() {
        head = tail = 0;
    }
    ~IntSLL();
    int isEmpty() {return head == 0;}
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
    void printList();
    int getSize();
private:
    IntSLLNode *head, *tail;
};
#endif

#include <iostream>

IntSLL::~IntSLL(){
    for(IntSLLNode *p; !isEmpty();) {
        p = head -> next;
        delete head;
        head = p;
    }
}

void IntSLL::addToHead(int e){
    head = new IntSLLNode(e, head);
    if(tail == 0) tail = head;
}

void IntSLL::addToTail(int e){
    if(tail != 0){
        tail->next = new IntSLLNode(e);
        tail = tail->next;
    }else{
        head = tail = new IntSLLNode(e);
    }
}

int IntSLL::deleteFromHead(){
    int e = head->info;
    IntSLLNode *tmp = head;
    if(head == tail) head = tail = 0;
    else head = head->next;
    delete tmp;
    return e;
}

int IntSLL::deleteFromTail(){
    int e = tail->info;
    if(head == tail) {
        delete head;
        head = tail = 0;
    }else{
        IntSLLNode *tmp;
        for(tmp = head; tmp->next != tail; tmp = tmp ->next); // traverse the list starting from head til you get to tail
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    return e;
}

void IntSLL::deleteNode(int e){
    if(head != 0){
        if(head == tail && e == head->info){
            delete head;
            head = tail = 0;
        }else if(e == head->info){
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;
        }else{
            IntSLLNode *pred, *tmp;
            for(pred=head, tmp = head->next; tmp != 0 && !(tmp->info == e);pred = pred->next, tmp = tmp->next);
            if(tmp != 0){
                pred->next = tmp->next;
                if(tmp == tail) tail = pred;
                delete tmp;
            }
        }
    }
}

bool IntSLL::isInList(int e) const{
    IntSLLNode *tmp;
    for(tmp = head; tmp!= 0 && !(tmp->info == e); tmp=tmp->next);
    return tmp != 0;
}

void IntSLL::printList(){
    // if list is Empty
    if(isEmpty()) std::cout << "List is empty" << std::endl;
    else if(head == tail){
        std::cout << head->info << std::endl;
    }else{
        IntSLLNode *tmp;
        for(tmp = head; tmp != 0; tmp = tmp->next){
            std::cout << tmp->info << std::endl;
        }
    }
}

int IntSLL::getSize(){
    unsigned int size = 0;
    IntSLLNode *tmp;
    for(tmp = head; tmp != 0; tmp = tmp->next) size++;
    return size;
}

int main(){
    IntSLL list;
    list.addToHead(10);
    list.addToHead(20);
    list.printList();
    std::cout << list.getSize() << std::endl;
}
