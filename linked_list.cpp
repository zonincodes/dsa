#include <iostream>
using namespace std;

// single Linked Lists

class IntSLLNode {
    public:
        IntSLLNode(){ // initializes the bext pointer to null 
            next = 0;
        }

        IntSLLNode(int i, IntSLLNode *in = 0){ // covers when a only one numeriacal argument is supplied by the user
            info = i; next = in;
        }

    int info; // used to store information, and this member is important to the user
    IntSLLNode * next; // used to link nodes to form a linked list
    // Note that IntSLLNode is defined
    // in terms of itself because one data member, next, is a pointer to a node of the same type that is
    //  just being defined.Objects that include such a data member are called self - referential objects.
};

int main()
{
    //  execute the declaration and assignment

    IntSLLNode *p = new IntSLLNode(10); // a new node is creadted

    cout << p ->info <<endl; // print the node infoe
    p -> next = new IntSLLNode(8); // constructor assigns number 8 to the info member of this node
    // the new node is inluded in the list by making the next of the first node a pointer to the new node
    cout << p-> next -> info << endl;

    return 0;
}