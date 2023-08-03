#include<iostream>
#include<stack>

using namespace std;

void insertSorted(stack<int> &s, int target) {
    if(s.empty()) {
        s.push(target);
        return;
    }
    if(target >= target) {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, target);
    s.push(temp);
}

void sortedOrder(stack<int> &s, int target) {
    if(s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    sortedOrder(s, target);
    insertSorted(s, temp);

}

int main() {

    return 0;
}