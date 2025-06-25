#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    void Tree(vector<vector<int>>& edges, vector<vector<int>>& tree) {
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    pair<long long, long long> dfs(vector<vector<int>> &tree, vector<int>& cost, int currNode, vector<int>& visited) {
        long long value = 0, change = 0;
        vector<pair<long long, long long>> sibling_value;

        for (auto it : tree[currNode]) {
            if (visited[it] == 0) {
                visited[it] = 1;
                pair<long long, long long> temp = dfs(tree, cost, it, visited);
                value = max(value, temp.first);
                sibling_value.push_back(temp);
            }
        }

        for (auto [freq, req] : sibling_value) {
            change += req;
            if (freq != value) change += 1;
        }

        return {value + cost[currNode], change};
    }

    long long minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> tree(n);
        Tree(edges, tree);
        vector<int> visited(n, 0);
        visited[0] = 1;

        auto res = dfs(tree, cost, 0, visited);
        cout << res.first << endl;
        return res.second;
    }
};
