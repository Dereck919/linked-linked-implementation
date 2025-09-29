#include<iostream>
#include<cstdlib>
using namespace std;
class DoublyNode{
    public:
    int data;
    DoublyNode* next;
    DoublyNode* previous;
    DoublyNode(int value){
        data = value;
        next = nullptr; 
        previous = nullptr;
    }
};
class DoublyLinkedList{
    public:
    DoublyNode* head = nullptr;
    DoublyNode* tail = nullptr;
    bool isCircular = false;
    void toggleCircular(){
        if(!isCircular){
            tail->next = head;
            isCircular = true;
        }else if(isCircular){
            tail->next = nullptr;
            isCircular = false;
        }
    }
    void push_front(int value){
        DoublyNode* newDoublyNode = new DoublyNode(value);
        if(head == nullptr){
            head = newDoublyNode;
            tail = newDoublyNode;
        }
        else{
            newDoublyNode->next = head;
            head->previous = newDoublyNode;
            head = newDoublyNode;
        }
    }
    void push_back(int value){
        DoublyNode* newDoublyNode = new DoublyNode(value);
            if(head == nullptr){
                head = newDoublyNode;
                tail = newDoublyNode;
            }
            else{
                newDoublyNode->previous = tail;
                tail->next = newDoublyNode;
                tail = newDoublyNode;
            }
        }
    void printList() {
        DoublyNode* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    int size(){
        DoublyNode* current = head;
        int i = 0;
        while(current!= nullptr){
            i+=1;
            current = current->next;
        }
        return i;
    }
    void insert(int i, int value){
        int length = size();
        if(i <1){
            push_front(value);
            return;
        }else if(i > size()){
            push_back(value);
            return;
        }
        DoublyNode* newDoublyNode = new DoublyNode(value);
        DoublyNode* current = head;
        int j = 0;
        while((current != nullptr) && (j!=(i-1))){
            current = current->next;
            j++;
        }
        DoublyNode* nextNode = current->next;
        newDoublyNode->next = nextNode;
        newDoublyNode->previous = current;
        nextNode->previous = newDoublyNode;
        current->next = newDoublyNode;
    }
    void erase(int i){
       if (head == nullptr){
        return;
       }
       int j = 0;
       DoublyNode* current = head;
       while((current!= nullptr) && (j != (i))){
            current = current->next;
            j++;
       }
       DoublyNode* nextNode = current->next;
       DoublyNode* lastNode = current->previous;
       lastNode->next = nextNode;
       nextNode->previous = lastNode;
       delete current;
    }
    DoublyNode* find(int value){
        DoublyNode* current = head;
        int j = 0;
        int length = size();
        while(j <= length){
            if(current->data == value){
                return current;
            }
            else{
                current = current->next;
                j++;
            }
        }
        return nullptr;
    }
    int getData(DoublyNode* DoublyNode){
        return DoublyNode->data;
    }
    void revprintList() {
        DoublyNode* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->previous;
        }
        cout << endl;
    }
};