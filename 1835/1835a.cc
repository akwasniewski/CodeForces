// k-th equality
// https://codeforces.com/contest/1835/problem/A
#include <iostream>
using namespace std;
int decpower(int digits) {
  int res = 1;
  for (int i = 1; i < digits; i++) {
    res *= 10;
  }
  return res;
}
int main() {
  int s;
  cin >> s;
  for (; s > 0; s--) {
  mainloop:
    if (s == 0)
      break;
    int a, b, c;
    long long k;
    cin >> a >> b >> c >> k;
    int decA = decpower(a);
    int decB = decpower(b);
    int decC = decpower(c);
    long long count = 0;
    for (int i = decA; i < decA * 10; i++) {
      if (decA == 0)
        continue;
      int min = decC - i;
      int max = decC * 10 - 1 - i;
      if (min < decB)
        min = decB;
      if (max >= decB * 10)
        max = decB * 10 - 1;
      int curCount = max - min + 1;
      if (curCount <= 0)
        continue;
      if (curCount + count < k) {
        count += curCount;
        continue;
      }
      for (int j = decB; j < decB * 10; j++) {
        if (i + j >= decC && i + j < decC * 10) {
          count++;
          if (count == k) {
            cout << i << " + " << j << " = " << i + j << "\n";
            s--;
            goto mainloop;
          }
        }
      }
    }
    cout << -1 << "\n";
  }
  return 0;
}
