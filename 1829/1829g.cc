// Hits Different
// https://codeforces.com/contest/1829/problem/G
#include <iostream>
using namespace std;
struct can {
  int lastS = -1;
  int leftParent = -1;
  int rightParent = -1;
  long long rightCount = 0;
  long long leftCount = 0;
  long long power = 1;
};
#define maxval 1000005
void GenerateTree(can tree[]) {
  int lastPrevRow = 1;
  long long cur = 2;
  int curLastRow = 1;
  int rowSize = 2;
  while (1 == 1) {
    for (int i = 0; i < rowSize; i++) {
      if (cur == maxval)
        return;
      tree[cur].power = cur * cur;
      if (i == 0) {
        tree[cur].rightParent = curLastRow;
      } else if (i == rowSize - 1) {
        tree[cur].leftParent = curLastRow;
        curLastRow++;
      } else {
        tree[cur].leftParent = curLastRow;
        curLastRow++;
        tree[cur].rightParent = curLastRow;
      }
      if (tree[cur].leftParent != -1) {
        tree[cur].leftCount = tree[tree[cur].leftParent].leftCount +
                              tree[tree[cur].leftParent].rightCount +
                              tree[tree[cur].leftParent].power;
      }
      if (tree[cur].rightParent != -1) {
        tree[cur].rightCount = tree[tree[cur].rightParent].rightCount +
                               tree[tree[cur].rightParent].power;
      }
      cur++;
    }
    rowSize++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  can *tree = new can[maxval];
  GenerateTree(tree);
  for (; s > 0; s--) {
    long long canNumber;
    cin >> canNumber;
    long long res = tree[canNumber].leftCount + tree[canNumber].rightCount +
                    tree[canNumber].power;
    cout << res << "\n";
  }
  delete[] tree;
}
