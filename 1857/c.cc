// Assembly via minimus
// https://codeforces.com/problemset/problem/1857/C
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int arrLen, minArrLen;
    cin >> arrLen;
    minArrLen = (long long)arrLen * ((long long)arrLen - 1) / 2;
    int arr[arrLen], minArr[minArrLen];
    for (int i = 0; i < minArrLen; i++) {
      cin >> minArr[i];
    }
    sort(minArr, minArr + minArrLen);
    int cur = 0;
    for (int i = 0; i < arrLen - 1; i++) {
      cout << minArr[cur] << " ";
      cur += arrLen - 1 - i;
    }
    cout << minArr[cur - 1];
    cout << "\n";
  }
}
