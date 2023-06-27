#include<iostream>
#include<vector> 
#include<limits.h>
#include <cstring>
using namespace std;

void subArray(vector<int>& v, int start,  int end)
{
  //base case
  if(end==v.size())
    return;
  //ek case solve
  for(int i=start; i<=end; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  subArray(v,start, end+1);

}

void printAllSubArray(vector<int>& v)
{
  for(int start=0; start<v.size(); start++)
  {
    int end = start;
    subArray(v,start, end);
  }
}

int main()
{
  vector<int> v{1,2,3,4,5};
  printAllSubArray(v);
  return 0;
}