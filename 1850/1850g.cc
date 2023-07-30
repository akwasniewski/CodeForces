// The morning star
// https://codeforces.com/problemset/problem/1850/G
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int pointCount;
    cin >> pointCount;
    map<int, int> xLines;
    map<int, int> yLines;
    map<int, int> xyLines;
    map<int, int> yxLines;
    for (int i = 0; i < pointCount; i++) {
      int x, y;
      cin >> x >> y;
      xLines.emplace(x, 0);
      xLines[x]++;
      yLines.emplace(y, 0);
      yLines[y]++;
      xyLines.emplace(x - y, 0);
      xyLines[x - y]++;
      yxLines.emplace(x + y, 0);
      yxLines[x + y]++;
    }
    long long sum = 0;
    for (auto cur : xLines) {
      sum += cur.second * ((long long)cur.second - 1);
    }
    for (auto cur : yLines) {
      sum += cur.second * ((long long)cur.second - 1);
    }
    for (auto cur : xyLines) {
      sum += cur.second * ((long long)cur.second - 1);
    }
    for (auto cur : yxLines) {
      sum += cur.second * ((long long)cur.second - 1);
    }
    cout << sum << "\n";
  }
}
