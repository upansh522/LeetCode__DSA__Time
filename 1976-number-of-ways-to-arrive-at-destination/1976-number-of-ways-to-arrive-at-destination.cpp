class Solution {
public:
    long long countPaths(long long n, vector<vector<int>>& roads) {
        const long long MOD = 1e9 + 7;
        vector<vector<pair<long long, long long>>> graph(n);
        for (long long i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            qu;
        qu.push({0, 0});
        vector<long long> visited(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        ways[0] = 1;
        visited[0] = 0;
        while (!qu.empty()) {
            auto [currTime, currNode] = qu.top();
            qu.pop();

            for (auto [nextNode, timeTaken] : graph[currNode]) {
                if (visited[nextNode] > currTime + timeTaken) {
                    ways[nextNode] = ways[currNode];
                    ways[nextNode]%= MOD ;
                    visited[nextNode] = currTime + timeTaken;
                    qu.push({currTime + timeTaken, nextNode});
                } else if (visited[nextNode] == currTime + timeTaken) {
                    ways[nextNode]= (ways[nextNode] +ways[currNode])%MOD;
                }
            }       
    }

    return ways[n - 1];
}
}
;