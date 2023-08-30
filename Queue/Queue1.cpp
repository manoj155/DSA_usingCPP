#include<iostream>
#include<queue>

using namespace std;

int main() {
    //creation
    queue<int> q;
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    //size
    cout << "Size of the Queue is: " << q.size() << endl;

    //removal
    q.pop();

    cout << "Size of the Queue is: " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Queue is not empty." << endl;
    }

    cout << "Front element of the queue is: " << q.front() << endl;

    return 0;    
}