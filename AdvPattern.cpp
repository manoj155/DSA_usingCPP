#include <iostream>

using namespace std;


// 4
//    1
//   232
//  34543
// 4567654

int main() {
  int n;
  cin >> n;

  for (int row = 0; row < n; row++) {
    // spaces
    for (int col = 0; col < n - row - 1; col++) {
      cout << " ";
    }
    // numbers
    int start = row + 1;
    for (int col = 0; col <= row; col++) {
      cout << start;
      start++;
    }

    start--; // decreamenting extra increament
    // reverse counting
    for (int col = 0; col < row; col++) {
      start -= 1;
      cout << start;
    }
    cout << endl;
  }
  return 0;
}