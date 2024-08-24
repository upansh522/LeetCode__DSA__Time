#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    // Find with path compression
    int find(std::vector<int> &parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    int removeStones(std::vector<std::vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        // Determine the size of the union-find structure
        for (int i = 0; i < n; i++) {
            maxRow = std::max(maxRow, stones[i][0]);
            maxCol = std::max(maxCol, stones[i][1]);
        }

        // Union-find initialization
        int totalNodes = maxRow + maxCol + 2; // Use maxRow+1 and maxCol+1 for unique indices
        std::vector<int> parent(totalNodes), size(totalNodes, 1);

        // Initialize the parent array
        for (int i = 0; i < totalNodes; i++) {
            parent[i] = i;
        }

        // Perform union operations
        for (int i = 0; i < n; i++) {
            int nodeRow = stones[i][0];
            int nodeCol = stones[i][1] + maxRow + 1;

            int rootRow = find(parent, nodeRow);
            int rootCol = find(parent, nodeCol);

            if (rootRow != rootCol) {
                if (size[rootRow] < size[rootCol]) {
                    parent[rootRow] = rootCol;
                    size[rootCol] += size[rootRow];
                } else {
                    parent[rootCol] = rootRow;
                    size[rootRow] += size[rootCol];
                }
            }
        }

        // Count distinct roots
        std::unordered_set<int> uniqueRoots;
        for (int i = 0; i < n; i++) {
            int nodeRow = stones[i][0];
            int nodeCol = stones[i][1] + maxRow + 1;
            uniqueRoots.insert(find(parent, nodeRow));
            uniqueRoots.insert(find(parent, nodeCol));
        }

        return n - uniqueRoots.size();
    }
};
