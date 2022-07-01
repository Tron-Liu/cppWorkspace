#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> m;
        vector<vector<int>>::iterator it1;
        vector<int>::iterator it2;

        for(it1 = edges.begin(); it1 != edges.end(); it1++) {
            for(it2 = it1->begin(); it2 != it1->end(); it2++) {
                map<int, int>::iterator mit = m.find(*it2);
                if(mit == m.end()) {
                    pair<int, int> p = {*it2, 1};
                    m.insert(p);
                }
                else
                    mit->second++;
            }
        }
        map<int, int>::iterator mit;
        int n = edges.size();
        int ans = 0;
        for(mit = m.begin(); mit != m.end(); mit++) {
            if(mit->second == n) ans = mit->first;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> edges = {{1,2}, {5,1}, {1,3}, {1,4}};
    cout << solution.findCenter(edges);
    return 0;
}