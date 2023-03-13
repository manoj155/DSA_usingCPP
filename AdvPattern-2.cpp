#include <iostream>

using namespace std;


// 8
//        1
//       1 2
//      1   3
//     1     4
//    1       5
//   1         6
//  1           7
// 1 2 3 4 5 6 7 8

int main() {
  int n;
  cin >> n;
  for(int row=0; row<n; row++)
    {
      for(int col=0; col<n-row-1; col++)
        {
          cout << " ";
        }
      if(row==0 || row==n-1)
      {
        if(row==0)
          cout << 1;
        else
        {
          int start = 0;
          for(int lc=0; lc<2*row+1; lc++)
                {
                  if(lc%2==0)
                    cout << ++start;
                  else
                    cout << " ";   
                }
        }
      }
      else
      {
        for(int col=0; col<2*row+1; col++)
          {
            if(col==0 || col==2*row)
            {
              if(col==0)
                cout << 1;
              else
                cout << row+1;
            }
            else
              cout << " ";
          }
      }

      cout << endl;
        
    }
  return 0;
}