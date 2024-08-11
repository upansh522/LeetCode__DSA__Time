#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n + 1); // n + 1 to handle 1-indexed nodes
        for (auto it : times)
        {
            graph[it[0]].push_back({it[1],it[2]}); // No need to adjust index if nodes are 1-indexed
        }

        vector<int> visited(n + 1, INT_MAX); // n + 1 to handle 1-indexed nodes
        queue<pair<int,int>>qu;
        qu.push({k, 0});
        visited[k] = 0;

        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                auto [currNode, currTime] = qu.front();
                qu.pop();
                for (auto it: graph[currNode])
                {
                    if (currTime + it.second < visited[it.first])
                    {
                        visited[it.first] = currTime + it.second;
                        qu.push({it.first, currTime + it.second});
                    }
                }
            }
        }

        int maxTime = *max_element(visited.begin() + 1, visited.end()); // +1 to skip the 0th index

        if (maxTime < INT_MAX)
            return maxTime;
        else 
            return -1;
    }
};
