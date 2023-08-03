#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int &target) {

    if(s.empty()) {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();

    //recursive call
    insertAtBottom(s, target);
    s.push(temp);
}

void reverseStack(stack<int>&s) {
    //base case
    if(s.empty()) return;

    int target = s.top();
    s.pop();

    //reverse stack
    reverseStack(s);

    //insert at bottom
    insertAtBottom(s, target);
}

void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
}

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "Stack before reverse ---->" << endl;
    printStack(s);

    reverseStack(s);
    cout << "Stack after reverse ---->" << endl;
    printStack(s);
    return 0;
}
