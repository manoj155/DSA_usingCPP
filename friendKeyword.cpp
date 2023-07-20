#include<iostream>

using namespace std;

class A {
    private:
        int x;
    public:
        A(int _val) { x = _val; }
        int getX() const{ 
            return x; 
        }

        void setX(int _val) {
            x = _val;
        }
    friend class B;
    //defining print as friend function
    friend void print(const A &);
};

class B {
    public:
        void print(const A&a) {
            cout << a.x << endl;
        }
};

void print(const A &a) {
    cout << "Inside friend function " << a.x << endl; 
}

int main() {
    A a(5);
    B b;
    //accessing data members from friend class.
    b.print(a);

    //accessing friend function
    print(a);
    return 0;
}