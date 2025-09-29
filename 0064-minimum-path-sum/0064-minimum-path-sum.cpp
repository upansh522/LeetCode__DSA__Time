class Solution {
public:
vector<pair<int,int>>dir={{1,0},{0,1}};
    int minPathSum(vector<vector<int>>& grid) {
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
};