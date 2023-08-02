#include<iostream>

using namespace std;

class Stack {
    public:
        int *arr;
        int top;
        int size;

        Stack(int size) {
            arr = new int[size];
            this->size = size;
            top = -1; 
        }
        void push(int data) {
            if(size - top > 1) {
                //space available
                //insert
                top++;
                arr[top] = data;
            }
            else {
                cout << "Stack overflow!";
            }
        }

        void pop() {
            if(top==-1) {
                //stack is empty
                cout << "Stack underflow, can't delete element." << endl;
            }
            else {
                //stack is not empty
                top--;
            }
        }

        int getTop() {
            if(top==-1) {
                cout << "There is no element in the stack" << endl;
                return -1;
            }
            else {
                return arr[top];
            }
        }

        //returns the number of valid element in the stack
        int getSize() {
            return top+1;
        }

        bool isEmpty() {
            if(top==-1) {
                return true;
            }
            else return false;
        }
};

int main() {
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "Size of the stack is: " << s.getSize() << endl;

    while(!s.isEmpty()) {
        cout << s.getTop() << " ";
        s.pop();
    }
    
    cout << endl;

    cout << "Size of the stack is: " << s.getSize() << endl;
    return 0;
}