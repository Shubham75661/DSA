
#include <iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int value;
        Node* next;
        
        Node(int val){
            this->prev = NULL;
            this->value = val;
            this->next = NULL;
        }
};

void insertAtstart(Node* &head, int val){
    Node* temp = new Node(val);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtlast(Node* &tail, int val){
    Node* temp = new Node(val);
    temp->prev = tail;
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void insertAtmiddle(Node* &head, Node* &tail, int val, int pos){
    if(pos == 1){
        insertAtstart(head, val);
        return;
    }
    
    int tempPos = 1;
    Node* temp = head;
    Node* temp2 = new Node(val);
    
    while(tempPos != pos){
        temp = temp->next;
        tempPos++;
    }
    
    temp2->next = temp;
    temp2->prev = temp->prev;
    temp->prev->next = temp2;
    temp->prev = temp2;
}

void deleteHead(Node* &head){
    Node* temp = head;
    head= head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deleteAttail(Node* tail){
    Node* temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
}

void deleteAtpos(Node* &head, Node* &tail, int pos){
    int tempPos = 1;
    Node* temp = head;
    while(tempPos != pos){
        temp = temp -> next;
        tempPos++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
}

void printData(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    return;
}

int main() {
    Node* node1 = new Node(10);
    
    Node* head = node1;
    Node* tail = node1;
    
    insertAtstart(head, 9);
    insertAtlast(tail, 11);
    insertAtlast(tail, 12);
    insertAtmiddle(head, tail, 33, 4);
    deleteAttail(tail);
    deleteAtpos(head, tail, 2);
    cout<<"HEAD "<<head->value;
    cout<<endl;
    cout<<"TAIL "<<tail->value;
    cout<<endl;
    cout<<"----------------";
    cout<<endl;
    printData(head);
    return 0;
}s