class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>qu;
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));

        qu.push({grid[0][0],{0,0}});
        ans[0][0]=grid[0][0];
        while(!qu.empty())
        {
            auto [currStep,currPos]=qu.front();
            auto [row,col]=currPos;
            qu.pop();
            if (ans[row][col]!=currStep){
            continue;
            }
            for (auto it:dir){
                int newRow=row+it.first;
                int newCol=col+it.second;
                if (newRow>=0 && newCol>=0 && newRow<n && newCol<m){
                    int newStep=currStep+grid[newRow][newCol];
                    if (ans[newRow][newCol]>newStep){
                        qu.push({newStep,{newRow,newCol}});
                        ans[newRow][newCol]=newStep;
                    }
                }
            }
        }

        return ans[n-1][m-1];
    }
};