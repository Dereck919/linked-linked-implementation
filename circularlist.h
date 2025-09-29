#include <iostream>
using namespace std;
class CircularNode{
    public:
    int data;
    CircularNode* next;
    CircularNode(int value){
        data = value;
        next = nullptr; 
    }
};
class CircularList{
    public:
    CircularNode* head = nullptr;
    CircularNode* tail = nullptr;
    void push_front(int value){
        CircularNode* newCircularNode = new CircularNode(value);
        if(head == nullptr){
            head = newCircularNode;
            tail = newCircularNode;
        }
        else{
            newCircularNode->next = head;
            head = newCircularNode;
            tail->next = head;
        }
    }
    void push_back(int value){
        CircularNode* newCircularNode = new CircularNode(value);
            if(head == nullptr){
                head = newCircularNode;
                tail = newCircularNode;
            }
            else{
                tail->next = newCircularNode;
                tail = newCircularNode;
                tail->next = head;
            }
        }
    void printList() {
        CircularNode* current = head;
        while (current != tail) {
            cout << current->data << " ";
            current = current->next;
        }
        if(tail != nullptr){
            cout << tail->data << " ";
        }
        cout << endl;
    }
    int size(){
        if(head == nullptr){
            return 0;
        }
        CircularNode* current = head;
        int i = 0;
        while(current->next != head){
            i+=1;
            current = current->next;
        }
        if(tail != nullptr){
            i++;
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
        CircularNode* newCircularNode = new CircularNode(value);
        CircularNode* current = head;
        int j = 0;
        while((current!= nullptr) && (j != (i-1))){
            current = current->next;
            j++;
        }
        CircularNode* nextCircularNode = current->next;
        current->next = newCircularNode;
        newCircularNode->next = nextCircularNode;
    }
    void erase(int i){
        if(head == nullptr){
            return;
        }
        CircularNode* previous = head;
        CircularNode* current = previous->next;
        CircularNode* next = current->next;
        if( i == 0){
            if(head = tail){
                delete head;
                head = nullptr;
                tail = nullptr;
            }else{
                CircularNode* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }
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
    CircularNode* find(int value){
        CircularNode* current = head;
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
    int getData(CircularNode* CircularNode){
        return CircularNode->data;
    }
    void clear() {
    CircularNode* current = head;
    int length = size();
    for(int i = 0; i < length; i ++){
        CircularNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}
bool isCircular(){
    if(tail->next == head){
        return true;
    }else{
        return false;
    }
}
};




