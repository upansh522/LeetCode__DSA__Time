class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>visited(m,vector<int>(n,0)),ans(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (mat[i][j]==0){
                    q.push({0,{i,j}});
                visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto [step,pos]=q.front();
            auto [row,col]=pos;
            q.pop();
            ans[row][col]=step;
            for (auto it:dir){
                int newRow=row+it.first;
                int newCol=col+it.second;
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n){
                    if (visited[newRow][newCol]==0){
                        q.push({step+1,{newRow,newCol}});
                        visited[newRow][newCol]=1;
                    }
                }
            }
        }

        return ans        ;
    }
};