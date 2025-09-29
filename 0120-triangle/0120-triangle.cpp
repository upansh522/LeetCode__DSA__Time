class Solution {
public:
long long f(vector<vector<int>>& grid, int row, int col, vector<unordered_map<int,int>>&dp){
    int n=grid.size();
    if (row==n-1){
        return grid[row][col];
    }

    if (dp[row].find(col)!=dp[row].end())return dp[row][col];

    return dp[row][col]=grid[row][col]+min(f(grid, row+1, col, dp), f(grid, row+1, col+1, dp));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<unordered_map<int,int>>dp(n);
        return f(triangle, 0, 0, dp);
    }
};