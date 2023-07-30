// love story
// https://codeforces.com/contest/1829/problem/A
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  string perfect = "codeforces";
  cin >> s;
  for (; s > 0; s--) {
    string str;
    cin >> str;
    int countDif = 0;
    for (int i = 0; i < 10; i++) {
      if (str[i] != perfect[i])
        countDif++;
    }
    cout << countDif << "\n";
  }
}
