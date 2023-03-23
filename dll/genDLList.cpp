#include "genDLList.h"
#include <string>
#include <iostream>

using namespace std;
int main() {
    string name = "John";
    DoublyLinkedList<string> names;
    names.addToDLLTail(name);
    names.addToDLLTail("kamau");
    names.addToDLLTail("Kevo");
    DLLNode head = names.getHead();
    DLLNode tail = names.getTail();

    cout << head.info << endl;
    cout << tail.info << endl;
    return 0;

}