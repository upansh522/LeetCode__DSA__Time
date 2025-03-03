class Solution {
public:
    int f(vector<int> nums, int ind, vector<vector<int>>& dp, int rem) {
        int n = nums.size();
        if (n==ind) {
            return nums[rem];
        }
        if (n-1==ind){
            return max(nums[rem],nums[ind]);
        }
        if (dp[ind][rem] != -1) {
            return dp[ind][rem];
        }
        int t1 = max(nums[ind],nums[ind+1]) + f(nums, ind + 2, dp, rem);
        int t2 = max(nums[ind+1],nums[rem]) + f(nums, ind + 2, dp, ind);
        int t3 = max(nums[ind],nums[rem]) + f(nums, ind + 2, dp, ind+1);

        return dp[ind][rem] = min({t1, t2, t3});
    }

    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(nums,1,dp,0);
    }
};