// Forever Winter
// https://codeforces.com/contest/1829/problem/F
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int s;
  cin >> s;
  for (; s > 0; s--) {
    int vertices, edges;
    cin >> vertices >> edges;
    vertices++;
    int vertexConnections[vertices];
    for (int i = 0; i < vertices; i++) {
      vertexConnections[i] = 0;
    }
    for (; edges > 0; edges--) {
      int first, second;
      cin >> first >> second;
      vertexConnections[first]++;
      vertexConnections[second]++;
    }
    int x = 0;
    int countX = 0;
    int y = 0;
    int countY = 0;
    for (int i = 0; i < vertices; i++) {
      if (vertexConnections[i] <= 1)
        continue;
      if (y == vertexConnections[i])
        countY++;
      else if (x == vertexConnections[i])
        countX++;
      else if (x == 0) {
        x = vertexConnections[i];
        countX++;
      } else if (y == 0) {
        y = vertexConnections[i];
        countY++;
      }
    }
    if (countY == 0) {
      y = x;
    } else if (countX > countY) {
      swap(x, y);
    }
    cout << x << " " << y - 1 << "\n";
  }
}
