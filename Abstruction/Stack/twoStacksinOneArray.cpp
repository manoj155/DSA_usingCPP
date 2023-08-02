#include<iostream>

using namespace std;

class Stack {
    public:
        int *arr;
        int top1;
        int top2;
        int size;

        Stack(int size) {
            arr = new int[size];
            this->size = size;
            top1 = -1; 
            top2 = size;
        }
        void push1(int data) {
            if(top2 - top1 > 1) {
                //space available
                //insert
                top1++;
                arr[top1] = data;
            }
            else {
                cout << "Stack overflow!";
            }
        }

        void pop1() {
            if(top1==-1) {
                //stack is empty
                cout << "Stack underflow, can't delete element." << endl;
            }
            else {
                //stack is not empty
                top1--;
            }
        }

        int getTop1() {
            if(top1==-1) {
                cout << "There is no element in the stack" << endl;
                return -1;
            }
            else {
                return arr[top1];
            }
        }

        //returns the number of valid element in the stack
        int getSize1() {
            return top1+1;
        }

        bool isEmpty1() {
            if(top1==-1) {
                return true;
            }
            else return false;
        }

        //2nd stack
        void push2(int data) {
            if(top2 - top1 > 1) {
                //space available
                //insert
                top2--;
                arr[top2] = data;
            }
            else {
                cout << "Stack overflow!";
            }
        }

        void pop2() {
            if(top2==size) {
                //stack is empty
                cout << "Stack underflow, can't delete element." << endl;
            }
            else {
                //stack is not empty
                top2++;
            }
        }

        int getTop2() {
            if(top2==size) {
                cout << "There is no element in the stack" << endl;
                return -1;
            }
            else {
                return arr[top2];
            }
        }

        //returns the number of valid element in the stack
        int getSize2() {
            return top2-(top1+1);
        }

        bool isEmpty2() {
            if(top2 == size) {
                return true;
            }
            else return false;
        }

        void print() {
            cout << endl;
            cout << "Top1: " << top1 << endl;
            cout << "Top2: " << top2 << endl;
            for(int i=0; i<size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        
};

int main() {
    Stack s(10);

    s.push1(10);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push1(40);
    s.print();
    s.push1(50);
    s.print();

    s.push2(100);
    s.print();
    s.push2(110);
    s.print();
    s.push2(120);
    s.print();
    s.push2(130);
    s.print();
    // s.push2(140);
    // s.print();
    return 0;
}