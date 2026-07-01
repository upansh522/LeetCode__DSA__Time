class Solution {
public:
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Multi-source BFS
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Max Heap (Modified Dijkstra)
        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (vis[r][c]) continue;
            vis[r][c] = 1;

            if (r == n - 1 && c == n - 1)
                return safe;

            for (auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !vis[nr][nc]) {

                    int newSafe = min(safe, dist[nr][nc]);
                    pq.push({newSafe, nr, nc});
                }
            }
        }

        return 0;
    }
};