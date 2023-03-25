#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int f(vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
        {
            int index = abs(nums[i])-1;
            if(nums[index]>0)
                nums[index] *= -1;
        }

    for(auto i:nums)
      cout << i << " ";

    for(int i=0; i<nums.size(); i++)
      if(nums[i]>=0)
        return i+1;
    return -1;
}

int main() {
    
    vector<int>v{3,0,1};
    cout << f(v);
    return 0;
}