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
	int m, n;			//m�У� n �� 
	cin >> m >> n;

	int p, q;			//��Ѱ����Ʒ��λ�� 
	cin >> p >> q;

	for (int i = 0; i < m; i++)		//�����Թ� 
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	Node root;			//��ʼ�������� 
	root.x = 0;
	root.y = 0;
	map[0][0] = 1;		//����������Ϊ�ѷ��� 

	st.push(root); 		//��ջ
	Node tmp, next;
	while (!st.empty()) {
		tmp = st.top();
		if (tmp.x == p && tmp.y == q) break;	//���ҵ���Ʒ

		//��ջ 
		if (tmp.x - 1 >= 0 && !map[tmp.x - 1][tmp.y]) {		//�� 
			tmp.x--;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}
		if (tmp.x + 1 < m && !map[tmp.x + 1][tmp.y]) {	//�� 
			tmp.x++;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}
		if (tmp.y - 1 >= 0 && !map[tmp.x][tmp.y - 1]) {		//�� 
			tmp.y--;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}
		if (tmp.y + 1 < n && !map[tmp.x][tmp.y + 1]) {		//�� 
			tmp.y++;
			st.push(tmp);
			map[tmp.x][tmp.y] = 1;
			continue;
		}

		//map[tmp.x][tmp.y] = 1;
		st.pop();	//���ϽԲ����㣬���ջ 
	}
	while (!st.empty()) {
		tmp = st.top();
		cout << tmp.x << " " << tmp.y << endl;
		st.pop();
	}

	return 0;
}
