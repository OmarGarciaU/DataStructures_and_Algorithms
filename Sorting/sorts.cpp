#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
using namespace std;

template<class T>
void fillArray(T array[], int size){
    for(int i{0}; i < size; i++){
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;
}

template<class T>
void printArray(T array[], int size){
    for(int i = 0; i<size; i++) cout << array[i] << " ";
    cout << endl;
}

template<class T>
void insertionSort(T array[], int size){
    cout << "Insertion Sort: " << endl;
    for(int i{1},j;i < size; i++){
        T tmp = array[i];
        for(j=i; j > 0 && tmp < array[j-1]; j--) {
            array[j] = array[j-1];
        }
        array[j] = tmp;
    }
}

template<class T>
void selectionSort(T array[], int size){
    for(int i = 0,j,least; i < size-1; i++){
        for(j = i+1,least = i; j < size; j++)
            if(array[j] < array[least]) least = j;
        swap(array[least], array[i]);
        printArray(array, size);
    }
}

template<class T>
void bubbleSort(T array[], int size){
    for(int i{0}; i < size-1; i++){
        for(int j = size-1; j > i; --j){
            if(array[j] < array[j-1]){
                cout << "pre-swap:  ";
                printArray(array, size);
                swap(array[j], array[j-1]);
                cout << "post-swap: ";
                printArray(array, size);
            }
        }
    }
}

int main(){
    srand(time(0));
    int array[5];
    int size = 5;

    fillArray(array, size);
    bubbleSort(array, size);
    for(int i{0}; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
