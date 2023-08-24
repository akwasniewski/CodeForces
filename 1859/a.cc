// United We Stand
//  https://codeforces.com/problemset/problem/1859/A
#include <algorithm>
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
    int arr[arrLen];
    bool wasUsed[arrLen];
    for (int i = 0; i < arrLen; i++) {
      cin >> arr[i];
      wasUsed[i] = false;
    }
    sort(arr, arr + arrLen);
    if (arr[0] == arr[arrLen - 1]) {
      cout << -1 << "\n";
      continue;
    }
    int count = 0;
    for (int i = arrLen - 1; i >= 0; i--) {
      if (arr[i] == arr[arrLen - 1])
        count++;
    }
    cout << arrLen - count << " " << count << "\n";
    for (int i = 0; i < arrLen - count; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < count; i++) {
      cout << arr[arrLen - 1] << " ";
    }
    cout << "\n";
  }
}
