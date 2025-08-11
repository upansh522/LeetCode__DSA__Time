class Solution {
    vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>visited(n,vector<int>(n,0));

        if (grid[0][0]==0){
            pq.push({1,{0,0}});
            visited[0][0]=1;
        }

        while(!pq.empty()){
            auto [step,pos]=pq.top();
            pq.pop();
            
            int currRow=pos.first; int currCol=pos.second;

            if (currRow==n-1 && currCol==n-1)
            return step;

            for (auto it:dir){
                int newRow=currRow+it.first;
                int newCol=currCol+it.second;

                if (newRow>=0 && newCol>=0 && newRow<n && newCol<n && grid[newRow][newCol]==0 && visited[newRow][newCol]==0){
                    visited[newRow][newCol]=1;
                    pq.push({step+1,{newRow,newCol}});
                }
            }
        }

        return -1;
    }
};