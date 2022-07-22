#include <iostream>
#include <vector>
using namespace std;

vector<int> size(10, 1);

int main() {
    vector<int> parents(10);
    for (int i = 0; i < parents.size(); i++)
        parents[i] = i;

    return 0;
}

int find(int a, const vector<int>& parents) {
    while (a != parents[a]) {
        parents[a] = parents[parents[a]];
        a = parents[a];
    }
    return a;
}

void my_union(int a, int b, vector<int>& parents) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a == root_b)
        return;

    if (size[root_a] > size[root_b]) {
        parents[root_b] = root_a;
        size[root_a] += size[root_b];
    } else {
        parents[root_a] = root_b;
        size[root_b] += size[root_a];
    }
}

bool connected(int a, int b, const vector<int>& parents) {
    int root_a = find(a, parents);
    int root_b = find(b, parents);

    if (root_a != root_b)
        return false;
    else
        return true;
}