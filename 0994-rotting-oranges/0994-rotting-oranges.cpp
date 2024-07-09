class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_map<int, unordered_map<int, int>> mp;
        queue<pair<int, int>> qu;
        int m = grid.size(), n = grid[0].size();
        int total = 0;
        bool rotten=false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2){
                    qu.push({i, j});
                    rotten=true;
                }

                if (grid[i][j] == 1 || grid[i][j] == 2) {
                    total++;
                }
            }
        }

        int time = 0;
        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                int row = qu.front().first, col = qu.front().second;
                qu.pop();

                if (mp[row][col] != 0) {
                    continue;
                }

                if (row + 1 < m && grid[row + 1][col] == 1) {
                    qu.push({row + 1, col});
                    grid[row + 1][col] = 2;
                }
                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    qu.push({row - 1, col});
                    grid[row - 1][col] = 2;
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    qu.push({row, col - 1});
                    grid[row][col - 1] = 2;
                }
                if (col + 1 < n && grid[row][col + 1] == 1) {
                    qu.push({row, col + 1});
                    grid[row][col + 1] = 2;
                }
                mp[row][col] = 1;
            }
            time++;
        }

          if (!rotten) {
            return total == 0 ? 0 : -1;
        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
                }
            }

        return time-1;        
    }
};
