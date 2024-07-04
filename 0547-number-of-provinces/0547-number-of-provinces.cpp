class Solution {
public:
    void findProvince(vector<vector<int>>& isConnected, int currInd, vector<bool>& visited) {
        visited[currInd] = true;
        for (int nextInd = 0; nextInd < isConnected.size(); ++nextInd) {
            if (isConnected[currInd][nextInd] == 1 && !visited[nextInd]) {
                findProvince(isConnected, nextInd, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                findProvince(isConnected, i, visited);
                ++ans;
            }
        }

        return ans;
    }
};
