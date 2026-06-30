#include <cstddef>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s, str;
    cout << "Enter a possbile palindrom: ";
    cin >> str;
    size_t size = str.length();
    cout << "Length of string: " << size << endl;
    stack<char> s1;
    stack<char>s2;

    bool isPal = true;

    //Remove the middle character if length is odd
    if(size % 2 == 1){
        int middle = size - ((size-1) / 2);
        middle--;
        for(int i{0}; i < size; i++){
            if(i!=middle){
                s+= str.at(i);
            }
        }
        size--;
    }

    //push letters on to stacks
    for(int i{0}, j = size-1; i< size/2; i++,j--){
        s1.push(s.at(i));
        s2.push(s.at(j));
    }

    //Compare both stacks
    while (!s1.empty() && !s2.empty()) {
        char ch1,ch2;
        ch1 = s1.top();
        ch2 = s2.top();
        if(ch1 != ch2) isPal = false;
        s1.pop();
        s2.pop();
    }

    //Print result
    if(isPal) cout << str << " is a palindrome!" << endl;
    else cout << str << " is not a palindrome!" << endl;
}
