// Olya and Game with Arrays
// https://codeforces.com/problemset/problem/1859/B
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int arrCount;
    cin >> arrCount;
    vector<int> arrs[arrCount];
    int min = INT32_MAX;
    int whereMin = -1;
    for (int i = 0; i < arrCount; i++) {
      int arrLen;
      cin >> arrLen;
      for (int j = 0; j < arrLen; j++) {
        int val;
        cin >> val;
        arrs[i].push_back(val);
      }
      sort(arrs[i].begin(), arrs[i].end());
      if (arrs[i].size() > 2)
        arrs[i].resize(2);
      if (min == -1)
        continue;
      if (arrs[i].empty()) {
        whereMin = i;
        min = -1;
      } else if (arrs[i].size() >= 2 && arrs[i][1] < min) {
        min = arrs[i][1];
        whereMin = i;
      }
    }
    long long sum = 0;
    int whereMin2 = -1;
    int min2 = INT32_MAX;
    for (int i = 0; i < arrCount; i++) {
      if (whereMin != i && !arrs[i].empty()) {
        sum += arrs[i].back();
      }
      if (!arrs[i].empty() && (whereMin == i || arrs[i].size() >= 2)) {
        if (arrs[i][0] < min2) {
          min2 = arrs[i][0];
        }
      }
    }
    if (min2 != INT32_MAX)
      sum += min2;
    cout << sum << "\n";
  }
}
