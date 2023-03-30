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

    public:
        IntSingleLinkedList(){
            head = tail = 0;
        }

        ~IntSingleLinkedList();

        bool isEmpty(){
            return head == 0;
        } 

        void addToHead(int);
        void addToTail(int);

        int deleteFromHead();
        int deleteFromTail();
        void deleteNode(int);

        bool isInList(int) const;


    private:
        IntSingleLinkedListNode *head, *tail;
};

#endif