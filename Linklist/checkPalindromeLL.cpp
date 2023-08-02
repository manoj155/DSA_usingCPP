#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

Node* reverse(Node* &head) {
    if(head->next==NULL) {
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = curr->next;
    while(curr!=NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool checkPalindrome(Node* &head) {
    if(head==NULL) {
        cout << "LL is empty" << endl;
        return true;
    }
    if(head->next==NULL) {
        //Single node
        return true;
    }

    //StepA: find the middle node
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && slow!=NULL) {
        fast = fast->next;
        if(fast!=NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    //Slow pointer is pointing to the middle node
    //StepB: Reverse LL after middle node
    Node* reverseLLKaHead = reverse(slow->next);

    //Compare the lists
    Node* temp = head;
    while(reverseLLKaHead!=NULL) {
        if(temp->data!=reverseLLKaHead->data)
            return false;
        temp = temp->next;
        reverseLLKaHead = reverseLLKaHead->next;
    }
    return true;
}
int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(20);
    Node* fifth = new Node(10);
    Node* sixty = new Node(30);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixty;

    bool isPalindrome = checkPalindrome(head);

    if(isPalindrome) {
        cout << "LL is Palindrome" << endl;
    }
    else {
        cout << "LL is not Palindrome" << endl;
    }
    return 0;
}