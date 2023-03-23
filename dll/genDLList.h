// ******************************** genDLList.h ****************************
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <class T>

class DLLNode {
    public: 
        DLLNode(){
            next = prev = 0;
        }

        DLLNode(const T &el, DLLNode *n = 0, DLLNode *p = 0){
            info = el; next = n; prev=p;
        }
        T info;
        DLLNode *next, *prev;
};


template <class T>
class DoublyLinkedList {
    public:
        DoublyLinkedList(){
            head = tail = 0;
        }

        void addToDLLTail(const T&);
        T deleteFromDLLTail();
        void addToHead(const T&);

    
    protected:
        DLLNode<T> *head, *tail;
};

template <class T>
void DoublyLinkedList<T>::addToDLLTail(const T &el){
    if(tail != 0){
        tail = new DLLNode<T>(el, 0, tail);
        taile -> prev-> next = tail;
    } else {
        head = tail = new DLLNode<T>(el);
    }
}

template <class T>
T DoublyLinkedList<T>::deleteFromDLLTail(){
    T el = tail->info;
    if(head == tail){
        delete head;
        head = tail = 0;
    } 
    else 
    {
        tail = tail -> prev;
        delete tail->next;
        tail -> next = 0;
    }

    return el;
}

template <class T>
void DoublyLinkedList<T>::addToHead(const T &el){
    head = new DLLNode(el, head)
    if(tail == 0){
        tail == head;
    }
}

#endif