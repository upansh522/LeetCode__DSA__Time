class Solution {
public:
   int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, set<int>> rowMap;  // row -> sorted columns
    unordered_map<int, set<int>> colMap;  // col -> sorted rows

    for (auto& b : buildings) {
        int x = b[0], y = b[1];
        rowMap[x].insert(y);
        colMap[y].insert(x);
    }

    int count = 0;

    for (auto& b : buildings) {
        int x = b[0], y = b[1];

        auto& row = rowMap[x];
        auto& col = colMap[y];

        bool hasLeft = *row.begin() < y;
        bool hasRight = *row.rbegin() > y;
        bool hasUp = *col.begin() < x;
        bool hasDown = *col.rbegin() > x;

        if (hasLeft && hasRight && hasUp && hasDown)
            count++;
    }

    return count;
}
};