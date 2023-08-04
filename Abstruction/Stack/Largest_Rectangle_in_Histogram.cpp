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

        while(s.top()!=-1 && input[s.top()] >= curr) {
            s.pop();
        }

        //chota element mil chukka hai
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> nextSmaller(vector<int> input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(input.size());

    for(int i=input.size()-1; i>=0; i--) {
        int curr = input[i];

        while(s.top()!=-1 && input[s.top()] >= curr) {
            s.pop();
        }

        //chota element mil chukka hai
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int getRectangularAreaHistogram(vector<int> &heights) {
    //step1: prev smaller
    vector<int> prev = prevSmaller(heights);

    //step2: next smaller
    vector<int> next = nextSmaller(heights);

    int size = heights.size();

    int maxArea = INT_MIN;
    for(int i=0; i<heights.size(); i++) {
        int length = heights[i];
        if(next[i] == -1) {
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;

        int area = length*width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout << "Ans is: " << getRectangularAreaHistogram(v) << endl;
    
    return 0;
}