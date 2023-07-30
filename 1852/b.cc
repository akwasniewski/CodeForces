// Imbalanced Arrays
// https://codeforces.com/problemset/problem/1852/B
#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  auto SortFirst = [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
  };
  auto SortSecond = [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  };
  for (; s > 0; s--) {
    int n;
    cin >> n;
    pair<int, int> nums[n];
    for (int i = 0; i < n; i++) {
      cin >> nums[i].first;
      nums[i].second = i;
    }
    sort(nums, nums + n, SortFirst);
    int positiveCount = 0;
    int left = 0;
    int right = n - 1;
    int i;
    for (i = 0; i < n; i++) {
      int positive = positiveCount + (n - i);
      int negative = positiveCount;
      if (positive == nums[left].first) {
        positiveCount++;
        nums[left].first = n - i;
        left++;
      } else if (negative == nums[left].first) {
        nums[left].first = i - n;
        left++;
      } else if (positive == nums[right].first) {
        positiveCount++;
        nums[right].first = n - i;
        right--;
      } else if (negative == nums[right].first) {
        nums[right].first = i - n;
        right--;
      } else {
        break;
      }
    }
    if (i != n)
      cout << "no\n";
    else {
      sort(nums, nums + n, SortSecond);
      cout << "yes\n";
      for (int i = 0; i < n; i++) {
        cout << nums[i].first << " ";
      }
      cout << "\n";
    }
  }
}
