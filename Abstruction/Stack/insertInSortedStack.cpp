#include<iostream>
#include<stack>

using namespace std;

void insertSorted(stack<int> &s, int target) {
    if(s.empty()) {
        s.push(target);
        return;
    }
    if(target <= s.top()) {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, target);
    s.push(temp);
}

void sortedOrder(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    sortedOrder(s);
    insertSorted(s, temp);
}

int main() {
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);

    sortedOrder(s);

    cout << "Printing: " << endl;
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    } cout << endl;
    return 0;
}