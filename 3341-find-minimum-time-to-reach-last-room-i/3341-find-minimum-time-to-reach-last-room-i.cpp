class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visit(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        int startTime=max(0,grid[0][0]);
        pq.push({0,{0,0}});
        visit[0][0]=1;
        while(!pq.empty()){
            auto [currTime,pos]=pq.top();
            auto[row,col]=pos;
            pq.pop();

            if (row==n-1 && col==m-1)return currTime;
            for(auto it:dir){
                int newRow=row+it.first;
                int newCol=col+it.second;

                if (newRow>=0 && newCol>=0 && newRow<n && newCol<m){
                    if (!visit[newRow][newCol]){
                        int newTime=max(currTime+1,grid[newRow][newCol]+1);
                        pq.push({newTime,{newRow,newCol}});
                        visit[newRow][newCol]=1;
                    }
                }
            }
        }
        return 0;
    }
};