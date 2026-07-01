#include <queue>
#include <stack>
#include <iostream>

using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<class T>
class Stack : public stack<T>{
};

template<class T>
class Queue : public queue<T> {
public:
    T dequeue(){
        T tmp = queue<T>::front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& e){
        push(e);
    }
};

template<class T>
class BSTNode {
public:
    BSTNode(){
        left = right = 0;
    }
    BSTNode(const T& el, BSTNode<T> *l = 0, BSTNode<T> *r = 0){
        e = el;
        left = l;
        right = r;
    }

    T e;
    BSTNode<T> *left, *right;
};

template<class T>
class BST{
public:
    BST(){
        root = 0;
    }

    ~BST(){
        clear();
    }

    void clear(){
        clear(root);
        root = 0;
    }

    bool isEmpty() const {
        return root == 0;
    }

    void preorder(){ // figure 6.11
        preorder(root);
    }

    void inorder(){ // figure 6.11
        inorder(root);
    }

    void postorder(){ // figure 6.11
        postorder(root);
    }

    T* search(const T& e) const { //figure 6.9
        return search(root, e);
    }

    void breadthFirst();                    //Completed
    void iterativePreorder();               //Completed
    void iterativeInorder();                //Completed
    void iterativePostorder();              //Completed
    void MorrisInorder();                   //Completed
    void insert(const T&);                  //Completed
    void deleteByMerging(BSTNode<T>*&);     //Completed
    void findAndDeleteByMerging(const T&);  //Completed
    void deleteByCopying(BSTNode<T>*&);     //Completed
    void balance(T*,int,int);               //Figure 6.37


protected:
    BSTNode<T>* root;
    void clear(BSTNode<T>*);                //Completed
    T* search(BSTNode<T>*, const T&) const; //Completed
    void preorder(BSTNode<T>*);             //Completed
    void inorder(BSTNode<T>*);              //Completed
    void postorder(BSTNode<T>*);            //Completed
    
    virtual void visit(BSTNode<T>* p){
        std::cout << p->e << ' ';
    }
};


template<class T>
void BST<T>::clear(BSTNode<T> *root){

}

template<class T>
T* BST<T>::search(BSTNode<T> *p, const T& e) const{
    while (p != 0) {
        if(e == p->e){
            return &p->e;
        }else if(e < p->e) p = p->left;
        else
         p = p->right;
    }
    return 0;
}

template<class T>
void BST<T>::breadthFirst(){
    Queue<BSTNode<T>> queue;
    BSTNode<T> *p = root;
    if (p != nullptr) {
        queue.enqueue(p);
        while (!queue.empty()) {
            p = queue.dequeue();
            visit(p);
            if(p->left != nullptr){
                queue.enqueue(p->left);
            }
            if(p->right != nullptr){
                queue.enqueue(p->right);
            }
        }
    }
}

template<class T>
void BST<T>::inorder(BSTNode<T> *p){
    if(p!=nullptr){
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template<class T>
void BST<T>::preorder(BSTNode<T> *p){
    if(p!=nullptr){
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T> *p){
    if(p!=nullptr){
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template<class T>
void BST<T>::iterativePreorder(){
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;
    if(p!=nullptr){
        travStack.push(p);
        while (!travStack.empty()) {
            p = travStack.pop();
            visit(p);
            if (p->right != nullptr) {
                travStack.push(p->right);
            }
            if(p->left != nullptr){
                travStack.push(p->right);
            }
        }
    }
}

template<class T>
void BST<T>::iterativePostorder(){
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root, *q = root;
    while(p!=nullptr){
        for(;p->left != nullptr; p = p->left) travStack.push(p);
        while (p->right == nullptr || p->right == q) {
            visit(p);
            q = p;
            if (travStack.empty()) {
                return;
            }
            p = travStack.pop();
        }
        travStack.push(p);
        p = p->right;
    }
}


template<class T>

void BST<T>::iterativeInorder(){
    Stack<BSTNode<T>*> travStack;
    BSTNode<T> *p = root;

    while(p!=nullptr){
        while(p!=nullptr){
            if (p->right) {
                travStack.push(p->right);
            }
            travStack.push(p);
            p = p->left;
        }
        p = travStack.pop();
        while (!travStack.empty() && p->right == nullptr) {
            visit(p);
            p = travStack.pop();
        }

        visit(p);
        if(!travStack.empty()) p = travStack.pop();
        else p = nullptr;
    }
}

template<class T>
void BST<T>::MorrisInorder(){
    BSTNode<T> *p = root, *tmp;
    while (p != nullptr) {
        if(p->left == nullptr){
            visit(p);
            p = p->right;
        }
        else {
            tmp = p->left;
            while (tmp->right != nullptr && tmp->right != p) {
                tmp = tmp->right;
            }

            if(tmp->right == nullptr){
                tmp->right = p;
                p = p->left;
            }
            else {
                visit(p);
                tmp->right = nullptr;
                p = p->right;
            }
        }
    }
}

template<class T>
void BST<T>::insert(const T& e){
    BSTNode<T> *p = root, *prev = nullptr;
    while (p != nullptr) {
        prev = p;
        if(e < p->e) p = p ->left;
        else p = p->left;
    }

    if(root == nullptr) root = new BSTNode<T>(e);
    else if(e < prev->e) prev->left = new BSTNode<T>(e);
    else prev->right                = new BSTNode<T>(e);
}

template<class T>
void BST<T>::deleteByMerging(BSTNode<T> *& node){
    BSTNode<T> *tmp = node;
    if(node != nullptr){
        if(!node->right){
            node = node ->left;
        }else if(node->left == nullptr){
            node = node->right;
        }else{
            tmp = node->left;
            while (tmp->right != nullptr) {
                tmp = tmp->right;
            }
            tmp->right = node->right;
            tmp = node;
            node = node->left;
        }
        delete tmp;
    }
}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& e){
    BSTNode<T> *node = root, *prev = nullptr;
    while (node != nullptr) {
        if (node->e == e) {
            break;
        }
        prev = node;
        if (e < node->e) {
            node = node->left;
        }else {
            node = node->right;
        }
    }
    if (node != nullptr && node->e == e) {
        if(node == root){
            deleteByMerging(root);
        }else if (prev->left == node) {
            deleteByMerging(prev->left);
        }else{
            deleteByMerging(prev->right);
        }
    }else if (root != nullptr) {
        std::cout << "element: " << e << "is not in the tree " << std::endl;
    }else {
        std::cout << "the tree is empty" << std::endl;
    }
}

template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node){
    BSTNode<T> *previous, *tmp = node;
    if(node->right == nullptr){
        node = node->right;
    }else if (node->left == nullptr) {
        node = node->right;
    }else{
        tmp = node->left;
        previous = node;
        while (tmp->right != nullptr) {
            previous = tmp;
            tmp = tmp->right;
        }
        node->e = tmp->e;
        if(previous == node) previous->left = tmp->left;
        else previous->right = tmp->left;
    }
    delete tmp;
}

template<class T>
void BST<T>::balance(T data[], int first, int last){
    if(first <= last){
        int middle = (first + last) / 2;
        insert(data[middle]);
        balance(data, first, middle-1);
        balance(data, middle+1, last);
    }
}

#endif
