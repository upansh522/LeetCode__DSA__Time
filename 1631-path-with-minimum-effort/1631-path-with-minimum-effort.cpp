#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rowSize = heights.size();
        int colSize = heights[0].size();
        
        // Min-heap to store the minimum effort path
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
        heap.push({0, {0, 0}});
        
        // Directions for movement: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Initialize visited vector with maximum possible effort
        vector<vector<int>> visited(rowSize, vector<int>(colSize, INT_MAX));
        visited[0][0] = 0;
        
        while (!heap.empty()) {
            auto [currentEffort, pos] = heap.top();
            heap.pop();
            
            int row = pos.first;
            int col = pos.second;
            
            if (row == rowSize - 1 && col == colSize - 1) {
                return currentEffort;
            }
            
            for (auto& direction : directions) {
                int newRow = row + direction.first;
                int newCol = col + direction.second;
                
                if (newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize) {
                    int newEffort = max(currentEffort, abs(heights[newRow][newCol] - heights[row][col]));
                    
                    if (newEffort < visited[newRow][newCol]) {
                        visited[newRow][newCol] = newEffort;
                        heap.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        
        return 0;  // This line should never be reached.
    }
};
