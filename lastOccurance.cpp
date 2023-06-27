#include<iostream>
#include<vector> 
#include<limits.h>
#include <cstring>
using namespace std;

void lastOccuranceLTR(string&s, int x, int i, int&ansIndex)
{
  //base condition
  if(i>=s.size())
    return;
  if(s[i]==x)
  {
    ansIndex = i;
  }
  lastOccuranceLTR(s,x,i+1,ansIndex);
}

void lastOccuranceRTL(string&s, int x, int i, int&ansIndex)
{
  //base condition
  if(i<0)
    return;
  if(s[i]==x)
  {
    ansIndex = i;
    return;
  }
  lastOccuranceRTL(s,x,i-1,ansIndex);
}


int main()
{
  string s;
  char x;
  cin >> s >> x;
  int ansIndex;
  lastOccuranceLTR(s, x, 0, ansIndex);
  cout << "(L->R) The last index of " << x << " is: " << ansIndex << endl;
  lastOccuranceRTL(s, x, s.size()-1, ansIndex);
  cout << "(R->L) The last index of " << x << " is: " << ansIndex << endl;

  //Using inbuilt function
  char str[s.size()];
  for(int i=0; i<s.size(); i++)
    {
      str[i] = s[i];
    }
  auto ch = strrchr(str,x);
  cout << "Using strrchr library function: " << ch-str << endl;
  return 0;
}