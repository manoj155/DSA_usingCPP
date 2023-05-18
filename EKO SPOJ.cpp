#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<long long int>trees, long long int m, long long int mid)
{
  long long int woodCollected = 0;
  for(int i = 0; i<trees.size(); i++)
  {
    if(trees[i]>mid)
    {
      woodCollected += trees[i] - mid;
    }
  }
  return woodCollected>=m;
}

long long int maxBladeHeight(vector<long long int>trees, long long int m)
{
  long long int start=0, end, ans=-1;
  end = *max_element(trees.begin(),trees.end());
  while(start<=end)
  {
    long long int mid = start + (end - start)/2;
    if(isPossibleSolution(trees, m, mid))
    {
      ans = mid;
      start = mid+1;
    }
    else
      end = mid-1;
  }
  return ans;
}

int main() {
  long long int n,m; //n --> no of trees m --> reqd wood
  cin >> n >> m;
  vector<long long int>trees;
  for(int i=0; i<n; i++)
  {
    int elt;
    cin >> elt;
    trees.push_back(elt);
  }

  cout << maxBladeHeight(trees,m) << endl;
  return 0;
}