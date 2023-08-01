////Ntarsis' Set
// https://codeforces.com/problemset/problem/1852/A
#include <algorithm>
#include <iostream>
using namespace std;
long long FirstFreePlace(int a[], int aCount, int &curPosInArr,
                         long long curPos, long long &curSkipped) {
  if (a[0] - 1 >= curPos) {
    return curPos * curPos;
  }
  for (; curPosInArr < aCount - 1; curPosInArr++) {
    if (curSkipped + a[curPosInArr + 1] - a[curPosInArr] - 1 >= curPos) {
      return curPos + a[curPosInArr] - curSkipped;
    }
    curSkipped += a[curPosInArr + 1] - a[curPosInArr] - 1;
  }
  return curPos + aCount;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int aCount, dayCount;
    cin >> aCount >> dayCount;
    int a[aCount];
    for (int i = 0; i < aCount; i++) {
      cin >> a[i];
    }
    sort(a, a + aCount);
    long long curPos = 1;
    int curPosInArr = 0;
    long long curSkipped = a[0] - 1;
    for (int i = 0; i < dayCount; i++) {
      curPos = FirstFreePlace(a, aCount, curPosInArr, curPos, curSkipped);
    }
    cout << curPos << "\n";
  }
}
