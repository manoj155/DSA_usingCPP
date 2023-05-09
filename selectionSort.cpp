#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v{5,4,3,2,1};
    for(int i=0; i<v.size()-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<v.size(); j++)
        {
            if(v[minIndex]>v[j])
                minIndex = j;
        }
        swap(v[i],v[minIndex]);
    }

  for(auto i:v)
    cout << i << " ";
   return 0;
}