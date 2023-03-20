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

    IntSLLNode *p = new IntSLLNode(10);

    cout << p ->info <<endl;
    p -> next = new IntSLLNode(8);
    cout << p-> next -> info << endl;

    return 0;
}