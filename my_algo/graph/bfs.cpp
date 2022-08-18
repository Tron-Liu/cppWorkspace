#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
  int x;
  int y;
};

int bfs(Point& start, Point& target);
int visited[5][4];

// 0 空地; 1 障碍物

int map[6][5] = {{1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}, {1, 0, 0, 0, 0},
                 {1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {1, 0, 0, 0, 1}};
int main() {
  Point start;
  start.x = 1;
  start.y = 1;

  Point target;
  target.x = 4;
  target.y = 3;

  // 0 没访问过; 1 访问过
  int visited[6][5] = {0};
  int steps = 0;
  steps = bfs(start, target);
  cout << "Steps: " << steps;
  return 0;
}

int bfs(Point& start, Point& target) {
  queue<Point> qu;
  qu.push(start);
  visited[1][1] = 1;

  Point tmp;
  int steps = 0;
  while (!qu.empty()) {
    int sz = qu.size();
    bool tag = false;
    for (int i = 0; i < sz; i++) {
      tmp = qu.front();
      qu.pop();
      // 到达目标点
      if (tmp.x == target.x && tmp.y == target.y) {
        tag = true;
        break;
      }

      int a = tmp.x;
      int b = tmp.y;

      Point t;
      // 左
      if (b - 1 > 0 && !visited[a][b - 1] && !map[a][b - 1]) {
        t.x = a;
        t.y = b - 1;
        qu.push(t);
        visited[a][b - 1] = 1;
      }
      // 下
      if (a + 1 <= 5 && !visited[a + 1][b] && !map[a + 1][b]) {
        t.x = a + 1;
        t.y = b;
        qu.push(t);
        visited[a + 1][b] = 1;
      }
      // 右
      if (b + 1 <= 4 && !visited[a][b + 1] && !map[a][b + 1]) {
        t.x = a;
        t.y = b + 1;
        qu.push(t);
        visited[a][b + 1] = 1;
      }
      // 上
      if (a - 1 > 0 && !visited[a - 1][b] && !map[a - 1][b]) {
        t.x = a - 1;
        t.y = b;
        qu.push(t);
        visited[a - 1][b] = 1;
      }
    }
    if (tag)
      return steps;
    steps++;
  }
}
