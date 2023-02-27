#include<iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  //upper traingle
  for(int row=0; row<n; row++)
    {
      //Spaces
      for(int col=n-row-1; col>0; col--)
        cout << " ";
      // * and spaces
      for(int col=0; col<2*row+1; col++)
        {
          if(col == 0 || col==2*row)
            cout << "*";
          else
            cout << " ";
        }
      cout << endl;
    }

  //lower traingle
  for(int row=0; row<n; row++)
    {
      //spaces
      for(int col=0; col<row; col++)
        cout << " ";

      // * and spaces
      for(int col=0; col<2*n-2*row-1; col++)
        {
          if(col==0 || col==2*n-2*row-2)
            cout<< "*";
          else
            cout<< " ";
        }
      cout << endl;
    }
  
}
