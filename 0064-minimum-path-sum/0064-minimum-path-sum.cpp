class Solution {
public:
// Graph Approach
int minPathSumUsingGraph(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<pair<int,int>>dir={{1,0},{0,1}};
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qu;
    qu.push({grid[0][0],{0,0}});
    while(!qu.empty()){
        auto [sum,currPos]=qu.top();
        int currRow=currPos.first,currCol=currPos.second;
        qu.pop();
        if (currRow==m || currCol==n){
            continue;
        }
        if (currRow==m-1 && currCol==n-1){
            return sum;
        }
        for (auto [increRow,increCol]: dir){
            if(currRow+increRow<m && currCol+increCol<n)
            qu.push({sum+grid[currRow+increRow][currCol+increCol],{currRow+increRow,currCol+increCol}});
        }
    }

    return 0;
}

//DP Approach
int f(vector<vector<int>>& grid, vector<vector<int>>&dp, int m, int n,vector<pair<int,int>>dir,int currRow, int currCol){
    if (currRow==m-1 && currCol==n-1){
        return grid[currRow][currCol];
    }

    for (auto [increRow,increCol]: dir){
        int nextRow=increRow+currRow,nextCol=increCol+currCol;
        if (nextRow<m && nextCol<n){
        if (dp[nextRow][nextCol]!=INT_MAX){
            dp[currRow][currCol]=min(dp[currRow][currCol],grid[currRow][currCol]+dp[nextRow][nextCol]);
        }else{
             dp[currRow][currCol]=min(dp[currRow][currCol],grid[currRow][currCol]+f(grid,dp,m,n,dir,nextRow,nextCol));
        }
        }
    }

    return dp[currRow][currCol];
}
    int minPathSum(vector<vector<int>>& grid) {
      /*  return minPathSumUsingGraph(grid); time complexity=m*n*(log(m*n)) TLE */

      //using DP
      int m=grid.size(),n=grid[0].size();
      vector<vector<int>>dp(m+1,vector<int>(n,INT_MAX));
      vector<pair<int,int>>dir={{1,0},{0,1}};
      return f(grid,dp,m,n,dir,0,0);
    }
};