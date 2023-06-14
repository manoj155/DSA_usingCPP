#include <iostream>
#include <string>
using namespace std;

string fibo(int n)
{
  string ans="";
  string first = "b";
  string second = "a";
  if(n==0)
    return "";
  else if(n==1)
    return "b";
  else if(n==2)
    return "a";

  for(int i=3; i<=n; i++)
  {
    ans = (second + first);
    cout << "First: "<< first << " Second: " <<second << " Ans: " << ans << " " << endl;
    first = second;
    second = ans;
  }
  return ans;
}

int main() {
  string fibonacciSeries = fibo(9);

  cout << fibonacciSeries << endl;
  cout << fibonacciSeries.size();
  return 0;
}
