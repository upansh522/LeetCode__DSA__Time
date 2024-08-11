class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up
        int d = 0, steps = 1;  // d is the direction index, steps is the number of steps in the current direction

        int currRow = rStart, currCol = cStart;

        ans.push_back({currRow, currCol});
        while (ans.size() < rows * cols) {
            for (int i = 0; i < 2; i++) {  // There are 2 turns for each complete cycle of directions
                for (int j = 0; j < steps; j++) {
                    currRow += directions[d][0];
                    currCol += directions[d][1];
                    if (currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols) {
                        ans.push_back({currRow, currCol});
                    }
                }
                d = (d + 1) % 4;  // Change direction
            }
            steps++;  // Increase the number of steps after every two directions (right-down or left-up)
        }

        return ans;
    }
};
