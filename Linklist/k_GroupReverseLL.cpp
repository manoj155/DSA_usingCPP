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

void print(Node* &head) {
    Node* temp = head;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* getMiddle(Node* &head) {
    if(head==NULL) {
        cout << "Link list is empty" << endl;
    } 
    if(head->next==NULL) {
        return head;
    }
    //LL has more than 1 node
    Node* slow = head;
    Node* fast = head;
    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast!=NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
    }
    return slow;
}

int getLength(Node* &head) {
    Node* temp = head;
    int len=0;
    while(temp!=NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}
Node* reverseKNodes(Node* &head, int k) {
    if(head==NULL) {
        cout << "empty link list" << endl;
        return NULL;
    }
    int len = getLength(head);
    if(len < k) {
        cout << "Enter a valid value for k." << endl;
        return head;
    }

    //it means no of node is greater than equal to k
    //Step A:
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    int count = 0;
    while(count<k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    //StepB:
    if(forward!=NULL) {
        //we still have nodes to reverse
        head->next = reverseKNodes(forward, k);
    }

    //Step C: Return head of the modified link list
    return prev;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << "Printing the link list: \n";
    print(head);

    cout << "Middle node is: " << getMiddle(head)->data << endl;

    head = reverseKNodes(head, 3);
    print(head);
    return 0;
}