#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(char first, char second)
{
  return first > second;
}

bool cmp1(int x, int y)
{
  return x > y;
}

int main()
{
  string s = "babbar";
  sort(s.begin(), s.end(), cmp);
  cout << s << endl;

  vector<int>v{5,3,1,2,4};
  sort(v.begin(), v.end(), cmp1);
  for(auto i: v)
    cout << i << " ";
}