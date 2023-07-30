// Hamon Oddysey
// https://codeforces.com/contest/1847/problem/B
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int vampireCount;
    cin >> vampireCount;
    unsigned int vampires[vampireCount];
    unsigned int weakestLink = UINT32_MAX;
    for (int i = 0; i < vampireCount; i++) {
      cin >> vampires[i];
      weakestLink &= vampires[i];
    }
    if (weakestLink != 0) {
      cout << 1 << "\n";
      continue;
    }
    int sum = 0;
    unsigned int curSubArray = 0;
    for (int i = 0; i < vampireCount; i++) {
      if (curSubArray == 0)
        curSubArray = vampires[i];
      else
        curSubArray &= vampires[i];
      if (curSubArray == 0) {
        sum++;
      }
    }
    cout << sum << "\n";
  }
}
