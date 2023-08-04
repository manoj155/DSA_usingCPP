#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> prevSmaller(vector<int> input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=0; i<input.size(); i++) {
        int curr = input[i];

        while(s.top() >= curr) {
            s.pop();
        }

        //chota element mil chukka hai
        ans[i] = s.top();
        s.push(curr);
    }

    // for(int i=0; i<ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    return ans;
}

vector<int> nextSmaller(vector<int> input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=input.size()-1; i>=0; i--) {
        int curr = input[i];

        while(s.top() >= curr) {
            s.pop();
        }

        //chota element mil chukka hai
        ans[i] = s.top();
        s.push(curr);
    }

    // for(int i=0; i<ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    return ans;
}

int main() {
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);

    vector<int> ans1 = nextSmaller(input);
    cout << "Next smaller elements: " << endl;
    for(int i=0; i<ans1.size(); i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;

    vector<int> ans2 = prevSmaller(input);
    cout << "Previous smaller elements: " << endl;
    for(int i=0; i<ans2.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
    
    return 0;
}