// 网络延迟时间

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class State {
public:
    int id;
    int time;

    State(int id, int time) {
        this->id = id;
        this->time = time;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
        toGraph(times, graph);

        // 标记节点是否被访问
        vector<bool> visited(n+1, false);
        visited[k] = true;

        // 记录最长路径
        vector<int> distTo(n+1, 0);
        distTo[k] = 0;

        queue<State> qu;
        
        qu.push( State(k, 0) );
        while( !qu.empty() ) {
            State node = qu.front();
            qu.pop();

            int curId = node.id;
            visited[curId] = true;
            int curtime = node.time;
            int nextTime = 0;

            if (curtime < distTo[curId]) {
                continue;
            }

            for(int nextId : adj(curId, graph)) {
                cout << nextId << endl;
                int distToNextNode = distTo[nextId] + graph[curId][nextId];
                if (distTo[nextId] < distToNextNode) {
                    distTo[nextId] = distToNextNode;
                    qu.push( State(nextId, distToNextNode) );
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if( !visited[i] ) return -1;
        }
        
        return getMax(distTo);
    }

    int getMax(vector<int> distTo) {
        int max = 0;
        for (int i : distTo) {
            if (max < i) max = i;
        }
        return max;
    }

    void toGraph(vector<vector<int>>& times, vector<vector<int>>& graph) {
        int sz = times.size();
        
        int u = 0, v = 0, w = 0;
        for (int i = 0; i < sz; i++) {
            u = times[i][0];
            v = times[i][1];
            w = times[i][2];

            graph[u][v] = w;
        }
    }

    // 返回 id 的相邻节点
    vector<int> adj(int id, vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int> res;
        for(int i = 1; i < sz; i++) {
            if (graph[id][i]) res.push_back(i);
        }
        return res;
    }
};

int main()
{
    int data1[] = {2, 1, 1};
    vector<int> time1(data1, data1 + 3);
    int data2[] = {2, 3, 1};
    vector<int> time2(data2, data2 + 3);
    int data3[] = {3, 4, 1};
    vector<int> time3(data3, data3 + 3);

    vector<vector<int>> times;
    times.push_back(time1);
    times.push_back(time2);
    times.push_back(time3);

    int n = 4, k = 2;
    Solution so;

    so.networkDelayTime(times, n, k);
    
    return 0;
}