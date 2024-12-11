class Solution {
public:
    int f(vector<int>& nums, int amt, vector<vector<int>>& dp, int ind) {
        int n = nums.size();
        if (ind == 0) {
            return (amt % nums[0] == 0);
        }

        if (dp[amt][ind] != -1) {
            return dp[amt][ind];
        }

        int notTaken = f(nums, amt, dp, ind - 1);
        int taken = 0;
        if (nums[ind] <= amt)
            taken=f(nums, amt - nums[ind], dp, ind);

        return dp[amt][ind] = taken + notTaken;
    }

    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amt + 1, vector<int>(n, -1));
        return f(coins, amt, dp, n - 1);
    }
};