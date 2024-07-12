class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat[0].size();
        int m=mat.size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>qu;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (mat[i][j]==0)
                {visited[i][j]=1;
                qu.push({i,{j,0}});}
            }
        }

        while(!qu.empty())
        {
            int row=qu.front().first;
            int col=qu.front().second.first;
            int path=qu.front().second.second;
            qu.pop();
            ans[row][col]=path;

            if (row+1<m && visited[row+1][col]==0)
            {
                visited[row+1][col]=1;
                qu.push({row+1,{col,path+1}});
            }
            if (row-1>=0 && visited[row-1][col]==0)
            {
                visited[row-1][col]=1;
                qu.push({row-1,{col,path+1}});
            }
            if (col-1>=0 && visited[row][col-1]==0)
            {
                visited[row][col-1]=1;
                qu.push({row,{col-1,path+1}});
            }
            if (col+1<n && visited[row][col+1]==0)
            {
                visited[row][col+1]=1;
                qu.push({row,{col+1,path+1}});
            }
        }

        return ans;
    }
};