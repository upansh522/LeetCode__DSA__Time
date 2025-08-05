class Solution {
public:
vector<pair<int,int>>dir={{1,0},{-1,0},{0,1}, {0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int currRow, int currCol, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>qu;
        vector<vector<int>>visit(m,vector<int>(n,-1));
        qu.push({currRow, currCol});
        int originalColor=image[currRow][currCol];
        image[currRow][currCol]=color;
        visit[currRow][currCol]=0;
        while(!qu.empty()){
            auto [row, col]=qu.front();
            qu.pop();
            for(auto it:dir){
                int newRow=row+it.first;
                int newCol=col+it.second;

                if (newCol>=0 && newRow>=0 && newRow<m && newCol<n && image[newRow][newCol]==originalColor && visit[newRow][newCol]==-1){
                    qu.push({newRow,newCol});
                    image[newRow][newCol]=color;
                    visit[newRow][newCol]=0;
                }
            }
        }
        return image;
    }
};