#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string f(int n)
{
    if(n==0)
      return "0";
    string str;
        while(n!=0)
        {
            if(abs(n%2)==1)
            {
                str += "1";
                n = (n-1)/(-2);
              cout << n << endl;
            }
            else
            {
                str += "0";
                n = n/(-2);
            }
        }
        reverse(str.begin(), str.end());
        return str;
}



int main() {
  
  int n;
  cin >> n;

  cout << f(n);
 

  return 0;
}