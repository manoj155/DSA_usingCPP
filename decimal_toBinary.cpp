#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int decimaltoBinary_UsingDivision(int n)
{
  int binaryNumber = 0;
  int i = 0;
  
  while(n>0)
    {
      int bit = n%2;
      binaryNumber = bit*pow(10,i++) + binaryNumber;
      n /= 2;
    }
  return binaryNumber;
}

int decimaltoBinary_UsingBitwise(int n)
{
  int binaryNumber = 0;
  int i = 0;
  
  while(n>0)
    {
      int bit = n&1;
      binaryNumber = bit*pow(10,i++) + binaryNumber;
      n = n >> 1;
    }
  return binaryNumber;
}

int main() {
  
  int n;
  cin >> n;

  cout << "Using Division: " << decimaltoBinary_UsingDivision(n) << endl;

  cout << "Using Bitwise operator: " << decimaltoBinary_UsingBitwise(n) << endl;
 

  return 0;
}