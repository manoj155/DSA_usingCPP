#include<iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  //upper traingle
  for(int row=0; row<n; row++)
    {
      //upper left
      // * and spaces
      for(int col=0; col<n-row; col++)
        {
          cout << "*";
        }
      //Spaces
      for(int col=0; col<row; col++)
        cout << " ";

      //upper right
      //spaces
      for(int col=0; col<row; col++)
        cout << " ";
      
      for(int col=0; col<n-row; col++)
        cout << "*";
      
      cout << endl;
    }

  //lower traingle
  for(int row=0; row<n; row++)
    {
      //lower left
      // * and spaces
      for(int col=0; col<=row; col++)
        {
          cout << "*";
        }
      //spaces
      for(int col=0; col<n-row-1; col++)
        cout << " ";

      //lower right
      //spaces
      for(int col=0; col<n-row-1; col++)
        cout << " ";
      
      // * and spaces
      for(int col=0; col<=row; col++)
        {
          cout << "*";
        }

      cout << endl;
    }
  
}
