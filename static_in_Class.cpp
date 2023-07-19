#include<iostream>

using namespace std;

class abc {
    public:
        int x, y;
    
        void print() const {
            //this
            cout << this->x << " " << this->y << endl;
        }
};

//static data members working example
class abc1 {
    public:
        static int x, y;
    
        void print() const {
            cout << x << " " << y << endl;
        }

        static void sprint() {
            cout << "I am in Static " << __FUNCTION__ << endl;
        }
};

//for static variable we need to define 
int abc1::x;
int abc1::y;

int main() {
    abc obj1 = {1, 2};
    abc obj2 = {4, 5};

    obj1.print();
    obj2.print();

    //shared variable
    abc1 obj3;
    abc1 obj4;
    obj3.x = 1;
    obj3.y = 2;
    obj3.print();
    obj4.x = 20;
    obj4.y = 30;
    obj4.print();
    obj3.print();
    
    //calling static function
    abc1::sprint();
    return 0;
}