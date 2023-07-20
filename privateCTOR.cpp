#include<iostream>

using namespace std;

class Box {
    int width;

    Box(int _width):width(_width) {};
    public:
        int getWidth() const{
            return width;
        }

        void setWidth(int _w) {
            width = _w;
        }
        friend class BoxFactory;
};

class BoxFactory {
    int count;

    public:

        Box getABox(int _w) {
            ++count;
            return Box(_w);
        }
};


int main() {
    BoxFactory bfact;
    Box b = bfact.getABox(5);
    cout << b.getWidth();
    return 0;
}

//visit "constructor c++ microsoft" for more information regarding constructor.