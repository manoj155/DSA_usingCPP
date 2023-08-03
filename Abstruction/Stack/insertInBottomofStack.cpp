#include<iostream>
#include<stack>

using namespace std;

void insertBottom(stack<int> &s, int &target) {

    if(s.empty()) {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();

    //recursive call
    insertBottom(s, target);
    s.push(temp);
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
    s.push(50);
    s.push(60);
    s.push(70);

    int target = 1000;


    //printStack(s);
    
    insertBottom(s, target);

    printStack(s);
    return 0;
}