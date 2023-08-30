#include<iostream>
#include<queue>

using namespace std;

class Queue {
    public:
    int *arr;
    int front, rear, size;

    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data) {
        if(rear == size) {
            cout << "Q is full." << endl;
        }
        else {
            arr[rear] = data;
            rear++;
        }
    }

    void pop() {
        if(front == rear) {
            cout << "Q is empty." << endl;
        }
        else {
            arr[front] = -1;
        }
    }
};

int main() {

    return 0;
}