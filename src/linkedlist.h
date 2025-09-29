#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr; 
    }
};
class LinkedList{
    public:
    Node* head = nullptr;
    Node* tail = nullptr;
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
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int value){
        Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    int size(){
        Node* current = head;
        int i = 0;
        while(current!= nullptr){
            i+=1;
            current = current->next;
        }
        return i;
    }
    void insert(int i, int value){
        if(i <1){
            push_front(value);
            return;
        }else if(i > size()){
            push_back(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        int j = 0;
        while((current!= nullptr) && (j != (i-1))){
            current = current->next;
            j++;
        }
        Node* nextNode = current->next;
        current->next = newNode;
        newNode->next = nextNode;
    }
    void erase(int i){
        if(head == nullptr){
            return;
        }
        Node* previous = head;
        Node* current = previous->next;
        Node* next = current->next;
        if( i == 0){
            head = current;
            delete previous;
            return;
        }
        int j = 0;
        while((current!= nullptr) && (j != (i-1))){
            previous = current;
            current = next;
            next = next->next;
            j++;
        }
        if(current == tail){
            tail = previous;
        }
        previous->next = next;
        delete current;
    }
    Node* find(int value){
        Node* current = head;
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
    int getData(Node* node){
        return node->data;
    }
    void clear() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}
};




