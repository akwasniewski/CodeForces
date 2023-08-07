// Array Coloring
// https://codeforces.com/problemset/problem/1857/A
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int arrLen;
    cin >> arrLen;
    int unevenCount = 0;
    for (int i = 0; i < arrLen; i++) {
      int num;
      cin >> num;
      if (num % 2) {
        unevenCount++;
      }
    }
    if (unevenCount % 2)
      cout << "no\n";
    else
      cout << "yes\n";
  }
}
