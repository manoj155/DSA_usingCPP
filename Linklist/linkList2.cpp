#include<iostream>

using namespace std;

class Node {
    public:

        int data;
        Node* next;
        //ctor1
        Node() {
            this->data = 0;
            this->next = NULL;
        }
        //ctor2
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

//I want to insert a node right at the head of the link list.
void insertAtHead(Node* &head, Node* &tail, int data) {
    //Step1:
    Node* newNode = new Node(data);

    //Step2:
    newNode->next = head;
    if(head == NULL) {
        tail = newNode;
    }

    //Step3:
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    //Step1:
    Node* newNode = new Node(data);

    //Step2:
    newNode->next = NULL;

    //Step3:
    if(tail == NULL) {
        tail = newNode;
        head = newNode;
    }
    else {
        tail->next = newNode;
    }

    //Step4: Update tail node
    tail = tail->next;
}

int findLength(Node* &head) {
    Node* temp = head;
    int count = 0;
    while(temp!=NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {

    //Check whether link list is empty
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);
    if(position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    //Step1: Find the position prev and curr
    Node* prev = head;
    for(int i=1; i<position; i++) {
        prev = prev->next;
    }
    Node* curr = prev->next;
    
    //Step2: Create new node
    Node* newNode = new Node(data);

    //Step3:
    newNode->next = curr;
    prev->next = newNode;

}

void print(Node* &head) {
    while(head!=NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node*  head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail, 20);
    insertAtHead(head,tail, 30);
    insertAtHead(head,tail, 40);
    insertAtHead(head,tail, 50);
    insertAtTail(head,tail, 10);
    insertAtPosition(100, 5, head, tail);



    print(head);
    return 0;
}