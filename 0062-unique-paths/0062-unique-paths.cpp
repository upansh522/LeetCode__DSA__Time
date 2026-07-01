class Solution {
public:
vector<pair<int,int>>dir={{1,0}, {0,1}};
int f(int m, int n, int currRow, int currCol, vector<vector<int>>& dp){
    if (currRow>=m || currCol>=n){
        return 0;
    }
    if (currRow==m-1 && currCol==n-1)return 1;
    for (auto it:dir){
        int row=it.first;
        int col=it.second;
        if (dp[currRow+row][currCol+col]!=0){
            dp[currRow][currCol]+=dp[currRow+row][currCol+col];
        }
        else{
            dp[currRow][currCol]+=f(m, n, currRow+row, currCol+col, dp);
        }
    }
    return dp[currRow][currCol];
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        return f(m, n, 0, 0,  dp);
    }
};