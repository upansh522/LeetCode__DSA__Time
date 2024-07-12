class Solution {
public:
void dfs(vector<vector<char>>& board,vector<vector<int>>&zeros,int row,int col){
    int m=board.size(),n=board[0].size();
    zeros[row][col]=0;
    if (row+1<m && zeros[row+1][col]==1 && board[row+1][col]=='O')
    {
        dfs(board,zeros,row+1,col);
    }
    if (row-1>=0 && zeros[row-1][col]==1 && board[row-1][col]=='O')
    {
        dfs(board,zeros,row-1,col);
    }
    if (col+1<n && zeros[row][col+1]==1 && board[row][col+1]=='O')
    {
        dfs(board,zeros,row,col+1);
    }
    if (col-1>=0 && zeros[row][col-1]==1 && board[row][col-1]=='O')
    {
        dfs(board,zeros,row,col-1);
    }

    return;
}
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> zeros(m,vector<int>(n,1));
        queue<pair<int,int>>qu;
        for (int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
            qu.push({0,i});
        }
        
        for (int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            qu.push({i,0});
        }

        for (int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O')
            qu.push({i,n-1});
        }
        for (int i=0;i<n;i++)
        {
            if(board[m-1][i]=='O')
            qu.push({m-1,i});
        }

        while(!qu.empty())
        {
            int row=qu.front().first;
            int col=qu.front().second;
            qu.pop();
            dfs(board,zeros,row,col);
        }

        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (zeros[i][j]==1)
                board[i][j]='X';
                else
                board[i][j]='O';
            }
        }

    }
};