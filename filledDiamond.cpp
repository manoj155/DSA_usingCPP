#include <iostream>

using namespace std;

int main() 
{
  // Print filled diamond
  
//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 
// * * * * * 
//  * * * * 
//   * * * 
//    * * 
//     * 

  // 1st phase
  
 //     * 
 //    * * 
 //   * * * 
 //  * * * * 
 // * * * * * 
  
  int n;
  cin >> n;
  for(int row=0; row<n; row++)
    {
      for(int col=n-row-1;col>0;col--)
        cout << " ";
      for(int k=0; k<=row; k++)
        cout << "* ";
      cout << endl;
    }


  //inverted triangle
  
  // * * * * * 
  //  * * * * 
  //   * * * 
  //    * * 
  //     * 
  
  for(int i=0; i<n; i++)
    {
      //loop for spaces
      for(int j=0;j<i;j++)
        cout << " ";
      //loop for *'s'
      for(int k=n-i; k>0; k--)
        cout << "* ";
      cout << endl;
    }

  
}