#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node() {
            this->data = 0;
            this->next = NULL;
            this->prev = NULL;
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        ~Node() {
            cout << "\n Node with value: " << this->data << " is deleted." << endl;
        }
};

void print(Node* &head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node* &head) {
    int len = 0;
    Node* temp = head;

    while(temp!=NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        //LL empty
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        //LL not empty
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        //LL empty
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        //LL not empty
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    else {
        if(position == 1) {
            insertAtHead(head, tail, data);
            return;
        }
        int len = getLength(head);
        if(len < position) {
            insertAtTail(head, tail, data);
            return;
        }

        //insert at middle
        //Step1: find prev and curr
        int i = 1;
        Node* prevNode = head;
        while(i<position-1) {
            prevNode = prevNode->next;
            i++;
        }
        Node* currNode = prevNode->next;

        //Step2:
        prevNode->next = newNode;
        newNode->prev = prevNode;

        currNode->prev = newNode;
        newNode->next = currNode;

    }
}

void deleteFromPos(Node* &head, Node* &tail, int position) {
    //empty
    if(head == NULL) {
        cout << "Link list is empty";
        return;
    }
    //single node
    if(head->next == NULL) {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    if(position == 1) {
        //Want to delete 1st node
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = getLength(head);
    if(position > len) {
        cout << "Please enter a valid position" << endl;
    }
    if(len == position) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    //delete from middle
    //step1: find left, curr, right
    int i = 1;
    Node* left = head;
    while(i<position-1) {
        left = left->next;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    //step2:
    left->next = right;
    //step3:
    right->prev = left;
    //step4:
    curr->next = NULL; curr->prev = NULL;
    //step5:
    delete curr;
    return;
}

int main() {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);

    cout << "\nAfter inserting 101 at head: ";
    insertAtHead(head, tail, 101);
    print(head);

    cout << "\nAfter inserting 201 at tail: ";
    insertAtTail(head, tail, 201);
    print(head);

    cout << "\n";
    insertAtPosition(head, tail, 401, 2);
    print(head);

    cout << "\n";
    deleteFromPos(head, tail, 6);
    print(head);
    
    return 0;
}