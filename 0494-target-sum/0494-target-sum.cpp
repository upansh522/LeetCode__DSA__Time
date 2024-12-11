class Solution {
public:
    int f(vector<int>& nums, int target, int sum, vector<vector<int>>& dp, int ind) {
        int n = nums.size();
        if (ind == n) {
            return (target == 0) ? 1 : 0; // Base case: one valid way if target is achieved
        }
        if (target + sum < 0 || target + sum >= 2 * sum + 1) {
            return 0;
        }

        if (dp[target + sum][ind] != -1) {
            return dp[target + sum][ind];
        }

        // Recursive calls
        int add = f(nums, target - nums[ind], sum, dp, ind + 1);
        int sub = f(nums, target + nums[ind], sum, dp, ind + 1);

        return dp[target + sum][ind] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) {
            return 0; // If target is not achievable, return 0
        }

        int n = nums.size();
        vector<vector<int>> dp(2 * sum + 1, vector<int>(n, -1));

        return f(nums, target, sum, dp, 0);
    }
};
