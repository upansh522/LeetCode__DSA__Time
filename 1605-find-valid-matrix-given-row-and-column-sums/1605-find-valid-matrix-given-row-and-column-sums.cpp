class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        
        // Corrected min-heap definitions
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rowMinHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> colMinHeap;

        for (int i = 0; i < rowSum.size(); i++) {
            rowMinHeap.push({rowSum[i], i});
        }

        for (int i = 0; i < colSum.size(); i++) {
            colMinHeap.push({colSum[i], i});
        }

        while (!rowMinHeap.empty() && !colMinHeap.empty()) {
            pair<int, int> rowEle = rowMinHeap.top();
            pair<int, int> colEle = colMinHeap.top();
            rowMinHeap.pop();
            colMinHeap.pop();

            int i = rowEle.second, j = colEle.second;
            int row = rowEle.first, col = colEle.first;

            ans[i][j] = min(row, col);

            if (row - ans[i][j] > 0) {
                rowMinHeap.push({row - ans[i][j], i});
            }
            if (col - ans[i][j] > 0) {
                colMinHeap.push({col - ans[i][j], j});
            }
        }

        return ans;
    }
};
