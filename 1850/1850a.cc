// To My Critics
// https://codeforces.com/problemset/problem/1850/A
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 10 || b + c >= 10 || a + c >= 10) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
