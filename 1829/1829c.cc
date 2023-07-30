// Mr. Perfectly Fine
// https://codeforces.com/contest/1829/problem/C
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int bookCount;
    cin >> bookCount;
    int bestFirst = INT32_MAX;
    int bestSecond = INT32_MAX;
    int bestBoth = INT32_MAX;
    for (int i = 0; i < bookCount; i++) {
      int time, skills;
      cin >> time >> skills;
      if (skills == 10) {
        if (bestFirst > time)
          bestFirst = time;
      } else if (skills == 1) {
        if (bestSecond > time)
          bestSecond = time;
      } else if (skills == 11) {
        if (bestBoth > time)
          bestBoth = time;
      }
    }
    if (bestBoth == INT32_MAX &&
        (bestFirst == INT32_MAX || bestSecond == INT32_MAX)) {
      cout << -1 << "\n";
      continue;
    }
    if (bestFirst == INT32_MAX || bestSecond == INT32_MAX ||
        bestBoth < bestFirst + bestSecond) {
      cout << bestBoth << "\n";
    } else
      cout << bestFirst + bestSecond << "\n";
  }
}
