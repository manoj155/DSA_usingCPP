#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int findFirstIndex(vector<int>& v, int target)
  {
        int s = 0;
        int e = v.size() - 1;

        int mid = s + (e - s) / 2;
        int idx = -1;

        while (s <= e) {
            if (v[mid] == target) {
            // search on left side coz target equal
            idx = mid;
            e = mid - 1;
            } else if (v[mid] < target) {
            // search on left side coz target is larger
            s = mid + 1;
            } else {
            // search on right side coz target is smaller
            e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return idx;
  }

int main() {

  vector<int> v{1, 3, 4, 4, 4, 4, 6, 7, 9};

  int target = 4;
  int ind = findFirstIndex(v, target);

  cout << ind;

  return 0;
}