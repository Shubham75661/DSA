
#include <iostream>
using namespace std;

class Node{
  public:
    int value;
    Node* next;
    
    Node(){
        this->value = NULL;
        this->next = NULL;
    }
    
    Node(int val){
        this->value = val;
        this->next = NULL;
    }
};

void insertAtstart(int val, Node* &head){
    Node* temp = new Node(val);
    temp -> next = head;
    head = temp;
    cout<<"Inserted "<<val<<" ";
    cout<<endl;
}

void insertAtlast(int val, Node* &tail){
    Node* temp1 = new Node(val);
    tail->next = temp1;
    tail = temp1;
}

void insertAtmiddle(Node* &head, int val, int pos){
    Node* temp = head; 
    int tempPos = 1;
    while(tempPos < pos-1){
        temp = temp->next;
        tempPos++;
    }
    
    Node* midNode = new Node(val);
    
    midNode->next = temp->next;
    temp->next = midNode;
}

void deleteAtpos(Node* &head, Node* &tail, int pos){
    Node* temp = head;
    Node* temp2;
    int tempPos = 1;
    if(pos == 1){
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    while(tempPos<pos-1){
        temp = temp->next;
        tempPos++;
    }
    temp2 = temp->next;
    if(temp2 -> next == NULL){
        temp->next = NULL;
        delete temp2;
        tail = temp;
        return;
    }
    temp->next = temp2->next;
    temp2->next = NULL;
    delete temp2;
}

void printlist(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    // insertAtstart(11, head);
    // insertAtstart(12, head);
    insertAtlast(9, tail);
    insertAtlast(8, tail);
    insertAtlast(7, tail);
    insertAtmiddle(head, 44, 3);
    deleteAtpos(head, tail, 5);
    cout<<"Head "<<head->value;
    cout<<endl;
    cout<<"Tail "<<tail->value;
    cout<<endl;
    printlist(head);
    return 0;
}