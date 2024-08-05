#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int, int>> qu;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        qu.push({0, 0});
        visited[0][0] = 1;
        int ans = 0;
        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        while (!qu.empty()) {
            int size = qu.size();
            ans++;
            for (int i = 0; i < size; i++) {
                int currRow = qu.front().first;
                int currCol = qu.front().second;
                qu.pop();

                if (currRow == n-1 && currCol == n-1)
                    return ans;

                for (auto& dir : directions) {
                    int newRow = currRow + dir.first;
                    int newCol = currCol + dir.second;

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 0 && visited[newRow][newCol] == 0) {
                        qu.push({newRow, newCol});
                        visited[newRow][newCol] = 1;
                    }
                }
            }
        }

        return -1;
    }
};
