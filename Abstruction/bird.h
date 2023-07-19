#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

using namespace std;

class Bird {
    public:

        virtual void eat() = 0;
        virtual void fly() = 0;
        //Classes that inherits this class has to implement pure virtual functions
};

class sparrow : public Bird {
    private:
        void eat() {
            cout << "Sparrow is eating." << endl;
        }
        void fly() {
            cout << "Sparrow is flying." << endl;
        }
};

class eagle : public Bird {
    private:
        void eat() {
            cout << "Eagle is eating." << endl;
        }
        void fly() {
            cout << "Eagle is flying." << endl;
        }
};

class pigeon : public Bird {
    private:
        void eat() {
            cout << "Pigeon is eating." << endl;
        }
        void fly() {
            cout << "Pigeon is flying." << endl;
        }
};

#endif 