// Ski Resort
// https://codeforces.com/contest/1840/problem/C
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int dayCount, minDays, maxTemp;
    cin >> dayCount >> minDays >> maxTemp;
    long long possibilities = 0;
    int daysInRow = 0;
    for (; dayCount > 0; dayCount--) {
      int temperature;
      cin >> temperature;
      if (temperature > maxTemp) {
        daysInRow = 0;
        continue;
      }
      daysInRow++;
      long long curPossibilities = daysInRow - minDays + 1;
      if (curPossibilities > 0)
        possibilities += curPossibilities;
    }
    cout << possibilities << "\n";
  }
}
