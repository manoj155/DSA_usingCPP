#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> v, int target)
{
  int s = 0;
  int e = v.size()-1;

  int mid = s + (e-s)/2;
  while(s<=e)
  {
    //These three conditions are for max 1-difference sorted arrays.
    if(v[mid]==target)
      return mid;
    if(mid-1>=s && v[mid-1]==target)
      return mid-1;
    if(mid+1<=e && v[mid+1]==target)
      return mid+1;
    
    if(v[mid]<target)
    {
      //right search
      s += 2;
    }
    else
    {
      //left search
      e -= 2;
    }
    mid = s + (e-s)/2;
  }
  return -1;
}

int main() {
  vector <int> v {10,3,40,20,50,80,70};
  cout << "Enter the target value: ";
  int target;
  cin >> target;
  int ans = binarySearch(v, target);
  cout << "Index of the required element is " << ans << endl;
  return 0;
}