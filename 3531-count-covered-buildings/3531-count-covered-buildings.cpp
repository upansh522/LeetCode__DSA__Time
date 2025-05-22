class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> row, col;

        // Step 1: Populate the row and col maps
        for (const auto& b : buildings) {
            row[b[0]].insert(b[1]); // y in row x
            col[b[1]].insert(b[0]); // x in col y
        }

        int count = 0;

        // Step 2: For each building, check if it is covered
        for (const auto& b : buildings) {
            int x = b[0], y = b[1];

            auto& r = row[x];
            auto& c = col[y];

            auto it_r = r.find(y);
            auto it_c = c.find(x);

            bool hasLeft = it_r != r.begin();
            bool hasRight = next(it_r) != r.end();
            bool hasUp = it_c != c.begin();
            bool hasDown = next(it_c) != c.end();

            if (hasLeft && hasRight && hasUp && hasDown)
                count++;
        }

        return count;
    }
};
