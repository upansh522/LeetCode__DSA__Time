#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> ans(n, INT_MAX);
        vector<vector<pair<int, int>>> graph(n);
        
        // Build the graph efficiently
        graph.reserve(n);
        for (const auto& it : edges) {
            int u = it[0], v = it[1], len = it[2];
            graph[u].emplace_back(v, len);
            graph[v].emplace_back(u, len);
        }

        // Use a set instead of priority queue for efficient updates
        set<pair<int, int>> pq;
        ans[0] = 0;
        pq.insert({0, 0});

        while (!pq.empty()) {
            auto [currLen, currNode] = *pq.begin();
            pq.erase(pq.begin());

            if (currLen >= disappear[currNode]) continue; // Skip if it's already disappeared

            for (auto& [nextNode, edgeWeight] : graph[currNode]) {
                int nextTime = currLen + edgeWeight;
                if (nextTime < ans[nextNode] && nextTime < disappear[nextNode]) {
                    pq.erase({ans[nextNode], nextNode}); // Remove the old pair
                    ans[nextNode] = nextTime;
                    pq.insert({nextTime, nextNode});
                }
            }
        }

        // Convert unreachable nodes from INT_MAX to -1
        for (int i = 0; i < n; ++i) {
            if (ans[i] == INT_MAX) ans[i] = -1;
        }

        return ans;
    }
};
