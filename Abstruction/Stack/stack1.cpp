#include<iostream>
#include<stack>

using namespace std;

int main() {
    // //intialization
    // stack<int> st;

    // //insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // //removal
    // st.pop();

    // //check element in the top
    // cout << "Element in the top is: " << st.top() << endl;

    // //size of the stack
    // cout << "Size of the stack is: " << st.size() << endl;

    // if(st.empty()) {
    //      cout << "Stack is empty" << endl;
    // }
    // else {
    //     cout << "Stack is not empty" << endl; 
    // }


    //printing a stack 
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop(); 
    }

    return 0;
}