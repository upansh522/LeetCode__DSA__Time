class Solution {
public:
vector<pair<int,int>>dir={{1,0},{0,1},{0,-1},{-1,0}};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>qu;
        vector<vector<int>>visited(m,vector<int>(n,0));
        
        for (int i=0;i<m;i++){
            if (board[i][0]=='O'){
                qu.push({i,0});
                visited[i][0]=1;
            }
            if (board[i][n-1]=='O'){
                qu.push({i,n-1});
                visited[i][n-1]=1;
            }
        }
        for (int i=0;i<n;i++){
            if (board[0][i]=='O'){
                qu.push({0,i});
                visited[0][i]=1;
            }
            if (board[m-1][i]=='O'){
                qu.push({m-1,i});
                visited[m-1][i]=1;
            }
        }

        while(!qu.empty()){
            auto [row, col]=qu.front();
            qu.pop();
            for (auto it:dir){
                int newRow=row+it.first;
                int newCol=col+it.second;

                if (newRow>=0 && newCol>=0 && newCol<n && newRow<m && board[newRow][newCol]=='O' && visited[newRow][newCol]==0){
                    qu.push({newRow, newCol});
                    visited[newRow][newCol]=1;
                }
            }
        } 

        for (int i=0;i<m;i++)       {
            for (int j=0;j<n;j++){
                if (visited[i][j]==1)board[i][j]='O';
                else board[i][j]='X';
            }
        }
        return;
    }
};