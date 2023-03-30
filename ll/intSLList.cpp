#include <iostream>
#include "intSLList.h"

IntSingleLinkedList::~IntSingleLinkedList(){
    for(IntSingleLinkedListNode *p; !isEmpty();){
        head-> next;
        delete head;
        head = p;
    }
}

void IntSingleLinkedList::addToHead(int el){
    head = new IntSingleLinkedListNode(el, head);
    if(tail == 0)
        tail = head;
}

void IntSingleLinkedList::addToTail(int el){
    if(tail != 0){
        tail -> next = new IntSingleLinkedListNode(el);
        tail = tail ->next;
    }
    else
        head = tail = new IntSingleLinkedListNode(el);
}

int IntSingleLinkedList::deleteFromHead(){
    int el = head ->info;
    IntSingleLinkedListNode *temp = head;
    if(head == tail) // if only node is the list;
        head = tail = 0;
    else 
        head = head -> next;
    
    delete temp;
    return el;
}

int IntSingleLinkedList::deleteFromTail(){
    int el = tail ->info;

    if(head==tail){
        delete head;
        head = tail = 0;

    } 
    else
    {
        IntSingleLinkedListNode * tmp;
        for(tmp = head; tmp -> next != tail; tmp = tmp->next)
        delete tail;
        tail = tmp;
        tail -> next = 0;
    }

    return el;
}

