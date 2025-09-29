class Solution {
public:
int graphSol(vector<vector<int>>& grid){
     int m=grid.size(), n=grid[0].size();
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];

        while(!pq.empty()){
            auto [sum, pos]=pq.top();
            pq.pop();

            auto [row,col]=pos;

            if (row==m-1 && col==n-1)return sum;

            for (auto [r,c]:dir){
                int newRow=row+r;
                int newCol=col+c;

                if (newRow>=0 && newRow<m && newCol>=0 && newCol<n && dist[newRow][newCol]>grid[newRow][newCol]+sum){
                    dist[newRow][newCol]=grid[newRow][newCol]+sum;
                    pq.push({dist[newRow][newCol],{newRow, newCol}});
                }
            }
        }
        return -1;
}

long long f(vector<vector<int>>&grid, int row, int col, vector<vector<int>>&dp){
    int m=grid.size(), n=grid[0].size();

    if (row>=m || col>=n)return INT_MAX;

    if (row==m-1 && col==n-1)return grid[row][col];

    if (dp[row][col]!=-1)return dp[row][col];
    return dp[row][col]=grid[row][col] + min(f(grid, row+1, col,dp), f(grid, row, col+1,dp));
}
vector<pair<int,int>>dir={{1,0},{0,1}};
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return f(grid, 0, 0,dp);
       
    }
};