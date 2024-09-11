class Solution {
public:
int f(int m, int n, vector<vector<int>>&dp, int currRow,int currCol){
    if (currRow==m || currCol==n){
        return 0;
    }
    if (currRow==m-1 && currCol==n-1){
        return 1;
    }
    vector<pair<int,int>> dir={{1,0},{0,1}};

    for (auto [increRow,increCol]: dir){
        if (dp[currRow+increRow][currCol+increCol]!=0){
            dp[currRow][currCol]+=dp[currRow+increRow][currCol+increCol];
        }
        else {
            dp[currRow][currCol]+=f(m,n,dp,currRow+increRow,currCol+increCol);
        }
    }

    return dp[currRow][currCol];
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        return f(m,n,dp,0,0);
    }
};