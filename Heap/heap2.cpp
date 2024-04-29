#include<iostream>
#include<queue>
using namespace std;

int main() {
    // //max-heap
    // priority_queue<int> pq;
    // pq.push(3);
    // pq.push(6);
    // pq.push(9);
    // pq.push(4);
    // pq.push(8);

    // cout << "Top element: " << pq.top() << endl;

    // pq.pop();
    // cout << "Top element: " << pq.top() << endl;

    // pq.pop();
    // cout << "Top element: " << pq.top() << endl;    
    
    // pq.pop();
    // cout << "Top element: " << pq.top() << endl;

    // pq.pop();
    // cout << "Top element: " << pq.top() << endl;

    // if(pq.empty()) {
    //     cout << "Max heap is empty" << endl;
    // }
    // else {
    //     cout << "Max heap is not empty" << endl;
    // }


    //Min-Heap

    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(3);
    minHeap.push(6);
    minHeap.push(9);
    minHeap.push(4);
    minHeap.push(8);

    cout << "Top element: " << minHeap.top() << endl;

    minHeap.pop();
    cout << "Top element: " << minHeap.top() << endl;

    minHeap.pop();
    cout << "Top element: " << minHeap.top() << endl;

    minHeap.pop();
    cout << "Top element: " << minHeap.top() << endl;

    minHeap.pop();
    cout << "Top element: " << minHeap.top() << endl;

    minHeap.pop();
    cout << minHeap.size() << endl;

    
    return 0;
}