class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1}};

    int dfs(vector<vector<int>>& grid, int i, int j,
            vector<vector<int>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n)
            return 0;

        if (grid[i][j] == 1)
            return 0;

        if (i == m-1 && j == n-1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (auto [dx, dy] : dir)
            ans += dfs(grid, i + dx, j + dy, dp);

        return dp[i][j] = ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(obstacleGrid, 0, 0, dp);
    }
};