// Character Blocking
// https://codeforces.com/contest/1840/problem/E
#include <iostream>
#include <queue>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    string word1, word2;
    cin >> word1 >> word2;
    int blockTime, queries;
    int differences = 0;
    for (int i = 0; i < word1.size(); i++) {
      if (word1[i] != word2[i])
        differences++;
    }
    cin >> blockTime >> queries;
    queue<pair<int, int>> que; //<index, when>
    for (int i = 0; i < queries; i++) {
      int cmd;
      cin >> cmd;
      if (!que.empty()) {
        auto cur = que.front();
        if (i - cur.second + 1 > blockTime) {
          que.pop();
          if (word1[cur.first] != word2[cur.first])
            differences++;
        }
      }
      if (cmd == 1) {
        int index;
        cin >> index;
        index--;
        if (word1[index] != word2[index])
          differences--;
        que.push(make_pair(index, i));
      }
      if (cmd == 2) {
        int firstWhich, secondPos, firstPos, secondWhich;
        cin >> firstWhich >> firstPos >> secondWhich >> secondPos;
        firstPos--;
        secondPos--;
        if (firstWhich != secondWhich && firstPos == secondPos) {
          swap(word1[firstPos], word2[secondPos]);
          continue;
        }
        if (word1[firstPos] != word2[firstPos])
          differences--;
        if (word1[secondPos] != word2[secondPos])
          differences--;
        if (firstWhich != secondWhich) {
          if (firstWhich == 1) {
            swap(word1[firstPos], word2[secondPos]);
          } else {
            swap(word2[firstPos], word1[secondPos]);
          }
        } else if (firstWhich == 1) {
          swap(word1[firstPos], word1[secondPos]);
        } else {
          swap(word2[firstPos], word2[secondPos]);
        }
        if (word1[firstPos] != word2[firstPos])
          differences++;
        if (word1[secondPos] != word2[secondPos])
          differences++;
      }
      if (cmd == 3) {
        if (differences == 0)
          cout << "yes\n";
        else
          cout << "no\n";
      }
    }
  }
}
