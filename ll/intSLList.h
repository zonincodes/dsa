#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSingleLinkedListNode{
    public:
        IntSingleLinkedListNode() {
            next = 0;
        }

        IntSingleLinkedListNode(int el, IntSingleLinkedListNode *ptr = 0)
        {
            info = el; next = ptr;
        }

        int info;
        IntSingleLinkedListNode *next;

};

class IntSingleLinkedList{

};

#endif