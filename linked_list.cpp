#include <iostream>
using namespace std;

// single Linked Lists

class IntSLLNode {
    public:
        IntSLLNode(){
            next = 0;
        }

        IntSLLNode(int i, IntSLLNode *in = 0){
            info = i; next = in;
        }

    int info;
    IntSLLNode * next;
};