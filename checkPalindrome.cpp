#include<iostream>
#include<vector> 
#include<limits.h>
#include <cstring>
using namespace std;

bool checkPalindrome(string& s, int start, int end)
{
  if(start>=end)
    return true;
  if(s[start]!=s[end])
    return false;
  checkPalindrome(s, start+1, end-1);
}
int main()
{
  string s;
  cin >> s;
  if(checkPalindrome(s,0,s.size()-1)) 
    cout << "True";
  else 
    cout << "False";
}