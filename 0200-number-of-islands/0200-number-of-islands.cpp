class Solution {
public:
void help(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j){
    queue<pair<int,int>>qu;
    int n=grid[0].size(), m=grid.size();
    qu.push({i,j});
    vis[i][j]=true;
    while(!qu.empty()){
        auto [row,col]=qu.front();
        qu.pop();
        for (auto it: dir){
            int newRow=row+it.first;
            int newCol=col+it.second;
            if (newRow >= 0 && newRow < m &&
                    newCol >= 0 && newCol < n && grid[newRow][newCol]=='1' && vis[newRow][newCol]==false){
                qu.push({newRow, newCol});
                vis[newRow][newCol]=true;
            }
        }
    }
}
vector<pair<int,int>>dir={{1,0}, {-1,0}, {0,-1}, {0,1}};
    int numIslands(vector<vector<char>>& grid) {
        int n=grid[0].size(), m=grid.size(), ans=0;
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]=='1' && vis[i][j]==false){
                    help(grid, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};