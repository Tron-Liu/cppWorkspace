#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int x;
	int y;
};

int map[52][52];

int main()
{
	stack<Node> st;
	int m, n;			//m行， n 列 
	cin >> m >> n;

	int p, q;			//待寻找物品的位置 
	cin >> p >> q;

	for (int i = 0; i < m; i++)		//输入迷宫 
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	Node root;			//初始化出发点 
	root.x = 0;
	root.y = 0;
	map[0][0] = 1;		//将出发点置为已访问 

	st.push(root); 		//进栈
	Node tmp, next;
	while (!st.empty()) {
		tmp = st.top();
		if (tmp.x == p && tmp.y == q) break;	//已找到物品

		//进栈 
		if (tmp.x - 1 >= 0 && !map[tmp.x - 1][tmp.y]) {		//上 
			tmp.x--;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}
		if (tmp.x + 1 < m && !map[tmp.x + 1][tmp.y]) {	//下 
			tmp.x++;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}
		if (tmp.y - 1 >= 0 && !map[tmp.x][tmp.y - 1]) {		//左 
			tmp.y--;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}
		if (tmp.y + 1 < n && !map[tmp.x][tmp.y + 1]) {		//右 
			tmp.y++;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}

		//map[tmp.x][tmp.y] = 1;
		st.pop();	//以上皆不满足，则出栈 
	}
	while (!st.empty()) {
		tmp = st.top();
		cout << tmp.x << " " << tmp.y << endl;
		st.pop();
	}

	return 0;
}
