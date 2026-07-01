#include <ios>
#include <iostream>
using namespace std;

int main(){
    int x;
    int *ptr1 = &x;
    int *ptr2 = &x;
    ptr1 = nullptr;
    ptr2 = 0;

    cout << boolalpha << (ptr1 == ptr2) << endl;
}
