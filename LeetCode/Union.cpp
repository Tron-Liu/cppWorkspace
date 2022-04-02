#include <iostream>
#include <vector>
using namespace std;

vector<int> w;

// 查找 x 的根节点
int find(int x, vector<int>& parent) {
    while (x != parent[x])
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

// 合并
void unio(int p, int q, vector<int>& parent) {
    int p_root = find(p, parent);
    int q_root = find(q, parent);

    if (p_root == q_root)
        return;
    
    if (w[p_root] >= w[q_root])
    {
        parent[q_root] = p_root;
        w[p_root] += w[q_root];
    }
    
    parent[p_root] = q_root;
}

int main()
{
    int count = 5;      // 节点个数
    vector<int> dp;
    for(int i = 1; i <= count; i++)
        dp.push_back(i);
    
    return 0;
}