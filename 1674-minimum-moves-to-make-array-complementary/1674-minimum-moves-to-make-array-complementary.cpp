class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<vector<int>> mm;
        int n = nums.size();
        int globalMax = 0, globalMin = INT_MAX;

        for (int i = 0; i < ceil(n / 2); i++) {
            int low = min(nums[i], nums[n - i - 1]) + 1;
            int high = max(nums[i], nums[n - i - 1]) + limit;
            mm.push_back({low, high});
            globalMax = max(globalMax, high);
            globalMin = min(globalMin, low);
        }

        vector<int> diffArray(globalMax - globalMin + 2, 0);
        diffArray[0] = n;

        for (int i = 0; i < mm.size(); i++) {
            diffArray[mm[i][0] - globalMin]--;
            diffArray[mm[i][1] - globalMin + 1]++;
        }

        for (int i = 0; i < ceil(n / 2); i++) {
            diffArray[nums[i]+nums[n - i - 1] - globalMin]--;
            diffArray[nums[i]+nums[n - i - 1] - globalMin + 1]++;
        }

        int sum = 0;
        int ans = n;

        for (int i = 0; i < diffArray.size(); i++) {
            sum += diffArray[i];
            ans = min(sum, ans);
        }

        return ans;
    }
};
