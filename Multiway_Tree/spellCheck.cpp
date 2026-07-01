#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "trie.h"
using namespace std;

char* strupr(char *s){
    char *ss;
    for (ss = s; *s = toupper(*s); s++);
    return ss;
}

int main(){
    char fileName[25], s[80], ch;
    int i, lineNum = 1;
    ifstream dictionary("dictionary");
    if(dictionary.fail()){
        cerr << "Cannot open dictionary" << endl;
        exit(-1);
    }
}
