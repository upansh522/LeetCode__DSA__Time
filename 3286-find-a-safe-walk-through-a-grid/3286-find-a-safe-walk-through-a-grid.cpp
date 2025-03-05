class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));  // Track max health at each cell

        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        
        priority_queue<pair<int, pair<int, int>>> qu; // Max heap based on health
        
        // Start position check
        if (grid[0][0] == 1 && health == 0) return false;

        qu.push({health, {0, 0}});
        visit[0][0] = 1;  

        while (!qu.empty()) {
            auto [currHealth, pos] = qu.top();
            int row = pos.first, col = pos.second;
            qu.pop();
            if (row == m - 1 && col == n - 1) return true;

            for (auto it : dir) {
                int newRow = row + it.first;
                int newCol = col + it.second;

                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n) {
                    int newHealth = currHealth - grid[newRow][newCol]; 
                    if (newHealth > 0 && visit[newRow][newCol]==0) {
                        visit[newRow][newCol] = 1;
                        qu.push({newHealth, {newRow, newCol}});
                    }
                }
            }
        }
        return false;
    }
};
