#include<iostream>
#include<stack>

using namespace std;


int main() {

    string name = "manoj";
    stack<char> s;

    for(int i=0; i<name.length(); i++) {
        s.push(name[i]);
    }

    while(s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}