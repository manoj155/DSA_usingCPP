#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int findPivotIndex(vector<int> v){
  int s = 0;
  int e = v.size()-1;

  int mid = s + (e-s)/2;

  while(s<e){
    if(v[mid]>v[mid+1])
      return mid;
    if(v[mid-1]>v[mid])
      return mid-1;
    if(v[s]>v[mid])
      e = mid-1;
    else if(v[s]<v[mid])
      s = mid+1;

    mid = s + (e-s)/2;
  }
}


int main() {

  vector<int> v{3,4,5,6,7,1,2};

  int ind = findPivotIndex(v);

  cout << "Index is: " << ind << " and Pivot element is: " << v[ind];

  

  return 0;
}