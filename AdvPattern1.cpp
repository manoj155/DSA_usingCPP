#include<iostream>

using namespace std;

// 5
// 1
// 2*2
// 3*3*3
// 4*4*4*4
// 5*5*5*5*5
// 5*5*5*5*5
// 4*4*4*4
// 3*3*3
// 2*2
// 1

int main()
{
  int n;
  cin >> n;

  for(int row=0; row<n; row++)
    {
      for(int col=0; col<row+1; col++)
        if(col==row)
          cout << row+1;
        else
          cout << row+1 << "*";
      cout << endl;
    }

  for(int row=n; row>0; row--)
    {
      for(int col=0; col<row; col++)
        if(col==row-1)
          cout << row ;
        else
          cout << row << "*";
      cout << endl;
    }
  
}
