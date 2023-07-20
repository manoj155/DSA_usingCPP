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

        //dtor
        ~Node() {
            cout << "Node with value " << this->data << " deleted." << endl;
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

void deleteNode(int position, Node* &head, Node* &tail) {
    if(head == NULL) {
        cout << "Cannot delete LL is empty." << endl;
        return;
    }
    //deleting first node
    if(position == 1) {
        cout << "Inside 1st node" << endl;
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);
    
    //deleting last node
    if(position == len) {
        cout << "Inside last node" << endl;
        //find prev
        int i=0;
        Node* prev = head;
        while(i<position-1) {
            prev = prev->next;
            i++;
        }
        //Step2:
        prev->next = NULL;
        //Step3:
        Node* temp = tail;
        //Step4:
        tail = prev;
        //step5:
        delete temp;
        return;
    }

    //deleting middle node
    //step: find prev and curr
    int i=1;
    Node* prev = head;
    while(i < position-1) {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    //step2:
    prev->next = curr->next;
    //step3:
    curr->next = NULL;
    //step4:
    delete curr;
    return;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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

    cout << "\nAfter deleting first node: \n";
    deleteNode(1, head, tail);
    print(head);

    cout << "\nAfter deleting last node: \n";
    deleteNode(3, head, tail);
    print(head);
    return 0;
}