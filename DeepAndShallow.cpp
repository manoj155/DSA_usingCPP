#include <iostream>

using namespace std;

class abc {

  public:
    int x#include <iostream>

using namespace std;

class abc {

  public:
    int x;
    int *y;

  abc(int _x, int _y): x(_x), y(new int(_y)) {}

  //Shallow copy
  // abc(const abc &obj) {
  //   x = obj.x;
  //   y = obj.y;
  // }

  //Smart deep copy constructor
  abc(const abc &obj) {
    x = obj.x;
    y = new int(*obj.y);
  }

  void print() const {
    printf("X:%d\nPTR Y:%p\nConetent of Y(*Y):%d",x, y, *y); 
  } 
    
};

int main() {
  cout << "Printing Object A:\n";
  abc a(1,2);
  a.print();
  cout << "\n\nPrinting Object B:\n";
  abc b = a;
  b.print();

  *b.y = 20;
  
  cout << "\n\nPrinting Object A:\n";
  a.print();
  cout << "\n\nPrinting Object B:\n";
  b.print();
  
};
    int *y;

  abc(int _x, int _y): x(_x), y(new int(_y)) {}

  //Shallow copy
  // abc(const abc &obj) {
  //   x = obj.x;
  //   y = obj.y;
  // }

  //Smart deep copy constructor
  abc(const abc &obj) {
    x = obj.x;
    y = new int(*obj.y);
  }

  void print() const {
    printf("X:%d\nPTR Y:%p\nConetent of Y(*Y):%d",x, y, *y); 
  } 
    
};

int main() {
  cout << "Printing Object A:\n";
  abc a(1,2);
  a.print();
  cout << "\n\nPrinting Object B:\n";
  abc b = a;
  b.print();

  *b.y = 20;
  
  cout << "\n\nPrinting Object A:\n";
  a.print();
  cout << "\n\nPrinting Object B:\n";
  b.print();
  
}