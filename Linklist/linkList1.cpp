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
    while(head!=NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "Printing the link list: \n";
    print(first);

    return 0;
}