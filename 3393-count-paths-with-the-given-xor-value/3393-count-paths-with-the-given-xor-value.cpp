class Solution {
public:
    int f(vector<vector<int>>& grid, int x, int y, vector<vector<unordered_map<int, int>>>& dp, int currXor, int k) {
        int MOD=1e9 +7;
        // Base case: If we're out of bounds, return 0
        if (x < 0 || y < 0) {
            return 0;
        }

        // Base case: If we reach the top-left corner, check if XOR matches `k`
        if (x == 0 && y == 0) {
            return (currXor ^ grid[x][y]) == k ? 1 : 0;
        }

        // If already computed, return the cached value
        if (dp[x][y].find(currXor) != dp[x][y].end()) {
            return dp[x][y][currXor];
        }

        // Recursive calls: Move left and up
        int left = f(grid, x - 1, y, dp, currXor ^ grid[x][y], k);
        int up = f(grid, x, y - 1, dp, currXor ^ grid[x][y], k);

        // Store the result in dp and return
        return dp[x][y][currXor] = (left + up)%MOD;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        // DP table to memoize results
        vector<vector<unordered_map<int, int>>> dp(m, vector<unordered_map<int, int>>(n));

        // Start the recursion from the bottom-right corner
        return f(grid, m - 1, n - 1, dp, 0, k);
    }
};
