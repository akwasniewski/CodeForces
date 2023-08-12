// Maximum Rounding
// https://codeforces.com/problemset/problem/1857/B
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    string x;
    cin >> x;
    bool addDigit = false;
    int lastCleared = x.length();
    for (int i = x.length() - 2; i >= 0; i--) {
      if (x[i + 1] >= '5') {
        for (int j = i + 1; j < lastCleared; j++) {
          x[j] = '0';
        }
        lastCleared = i + 1;
        if (x[i] == '9') {
          while (x[i] != '9' && i >= 0) {
            if (i == 0) {
              addDigit = true;
            }
            x[i] = '0';
            i--;
          }
          if (i >= 0) {
            x[i] += 1;
          }
        } else {
          x[i] += 1;
        }
      }
    }
    if (x[0] >= '5') {
      x[0] = '0';
      addDigit = true;
      for (int j = 1; j < lastCleared; j++) {
        x[j] = '0';
      }
    }
    if (addDigit) {
      cout << 1;
    }
    cout << x << "\n";
  }
}
