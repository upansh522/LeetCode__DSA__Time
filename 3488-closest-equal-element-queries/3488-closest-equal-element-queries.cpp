class Solution {
public:
    int binarySearchUpper(vector<int>& v, int ind) {
        int l = 0, h = v.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (v[mid] <= ind) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l;
    }

    int binarySearchLower(vector<int>& v, int ind) {
        int l = 0, h = v.size() - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (v[mid] < ind) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return h;
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& q) {
        int n = nums.size(), m = q.size();
        unordered_map<int, vector<int>> mp;
        vector<int> ans(m, -1);

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            int ind = q[i];
            auto& v = mp[nums[ind]];

            if (v.size() < 2)
                continue;

            int vSize = v.size();

            int l = binarySearchUpper(v, ind);
            int h = binarySearchLower(v, ind);

            int upperDist = (l < vSize) ? abs(v[l % vSize] - ind) : abs((v[0] + n) - ind);
            int lowerDist = (h >= 0) ? abs(v[h] - ind) : abs((v[vSize - 1] - n) - ind);

            ans[i] = min(upperDist, lowerDist);
        }

        return ans;
    }
};
