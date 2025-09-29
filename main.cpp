#include"linkedlist.h"
#include "doublylinkedlist.h"
#include "circularlist.h"


int main(){

    //SINGLY LINKED LIST
    cout << "---------------------" << endl;
    cout << "SINGLY LINKED LIST" << endl;
    LinkedList linkedList;
    linkedList.push_front(18);
    linkedList.push_front(1);
    linkedList.push_front(1);
    linkedList.push_front(73);
    linkedList.push_front(59);
    linkedList.push_back(55);
    linkedList.printList();
    cout << "size: " << linkedList.size() << endl;
    linkedList.insert(5, 99);
    linkedList.erase(4);
    linkedList.printList();
    Node* node = linkedList.find(73);
    cout << "Data found: " << node->data << endl;
    //END SINGLY LINKED LIST
    

    //START DOUBLY LINKED LIST
    cout << "---------------------" << endl;
    cout << "DOUBLY LINKED LIST" << endl;
    DoublyLinkedList doublyList;
    doublyList.push_front(18);
    doublyList.push_front(1);
    doublyList.push_front(1);
    doublyList.push_front(73);
    doublyList.push_front(59);
    doublyList.push_back(55);
    doublyList.printList();
    cout << "size: " << doublyList.size() << endl;
    doublyList.insert(5, 99);
    doublyList.erase(4);
    doublyList.printList();
    doublyList.revprintList();
    DoublyNode* doublyNode = doublyList.find(73);
    cout << "Data found: " << doublyNode->data << endl;
    //END DOUBLY LINKED LIST

    //START CIRCULARY LINKED LIST
    cout << "---------------------" << endl;
    cout << "CIRCULARY LINKED LIST" << endl;
    CircularList circList;
    circList.push_front(18);
    circList.push_front(1);
    circList.push_front(1);
    circList.push_front(73);
    circList.push_front(59);
    circList.push_back(55);
    circList.printList();
    cout << "size: " << circList.size() << endl;
    circList.insert(5, 99);
    circList.erase(4);
    circList.printList();
    CircularNode* circNode = circList.find(73);
    cout << circNode->data << endl;
    cout << "(1 = true/0 = false) " << circList.isCircular();
}