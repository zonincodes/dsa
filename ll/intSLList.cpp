#include <iostream>
#include "intSLList.h"

IntSingleLinkedList::~IntSingleLinkedList()
{
    for (IntSingleLinkedListNode *p; !isEmpty();)
    {
        head->next;
        delete head;
        head = p;
    }
}

void IntSingleLinkedList::addToHead(int el)
{
    head = new IntSingleLinkedListNode(el, head);
    if (tail == 0)
        tail = head;
}

void IntSingleLinkedList::addToTail(int el)
{
    if (tail != 0)
    {
        tail->next = new IntSingleLinkedListNode(el);
        tail = tail->next;
    }
    else
        head = tail = new IntSingleLinkedListNode(el);
}

int IntSingleLinkedList::deleteFromHead()
{
    int el = head->info;
    IntSingleLinkedListNode *temp = head;
    if (head == tail) // if only node is the list;
        head = tail = 0;
    else
        head = head->next;

    delete temp;
    return el;
}

int IntSingleLinkedList::deleteFromTail()
{
    int el = tail->info;

    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        IntSingleLinkedListNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
            delete tail;
        tail = tmp;
        tail->next = 0;
    }

    return el;
}

void IntSingleLinkedList::deleteNode(int el)
{
    // if none empty list
    if (head != 0)
    {
        // if only one node in the list;
        if (head == tail && head->info == el)
        {
            delete head;
            head = tail = 0;
        }
        else if (el == head->info)
        {
            IntSingleLinkedListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        else
        {
            IntSingleLinkedListNode *pred, *tmp;

            for (pred = head, tmp = head->next;
                 tmp != 0 && !(tmp->info == el); tmp = tmp->next)
                ;

            if (tmp != 0)
            {
                pred->next = tmp->next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
    }
}

bool IntSingleLinkedList::isInList(int el) const
{
    IntSingleLinkedListNode *tmp = head;
    for (; tmp != 0 && !(tmp->info == el); tmp = tmp->next)
        ;
    return tmp != 0;
}