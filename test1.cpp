#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

const int N = 55;

int n, m;
string g[N];
int dist[N][N];
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};

void bfs() {
  queue<pair<int, int> > q;
  memset(dist, -1, sizeof(dist));
  dist[n - 1][m - 1] = 0;
  q.push({n - 1, m - 1});  //头结点进队
  while (q.size()) {
    pair<int, int> t = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1 && g[x][y] == '0') {
        dist[x][y] = dist[t.first][t.second] + 1;
        q.push({x, y});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> g[i];

  bfs();
  cout << dist[0][0] << endl;

  int x = 0, y = 0;

  string res;
  while (x != n - 1 || y != m - 1) {
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '0') {
        if (dist[x][y] == 1 + dist[nx][ny]) {
          x = nx, y = ny;
          res += dir[i];
          break;
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}
