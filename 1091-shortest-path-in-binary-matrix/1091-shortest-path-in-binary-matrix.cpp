class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0},   {0, 1},  {0, -1}, {-1, 0},
                                  {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        if (grid[0][0]==1)return-1;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()) {
            ans++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [row, col] = q.front();
                q.pop();
                if (row == n - 1 && col == n - 1)
                    return ans;
                for (auto it : dir) {
                    int newRow = row + it.first;
                    int newCol = col + it.second;
                    if (newRow < n && newRow >= 0 && newCol < n &&
                        newCol >= 0) {
                        if (visited[newRow][newCol] == 0 &&
                            grid[newRow][newCol] == 0) {
                            q.push({newRow, newCol});
                            visited[newRow][newCol] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};