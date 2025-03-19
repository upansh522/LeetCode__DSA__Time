class Solution {
public:
    int f(vector<int>& nums, int ind, int ind2, vector<vector<int>>& dp) {
        int n = nums.size();
        if (ind == n)
            return 0;

        if (dp[ind][ind2 + 1] != -1) {
            return dp[ind][ind2 + 1];
        }

        int t = 0;
        if (ind2 == -1 || nums[ind] > nums[ind2])
            t = 1 + f(nums, ind + 1, ind, dp);
        // notTake
        int nt = f(nums, ind + 1, ind2, dp);

        return dp[ind][ind2 + 1] = max(t, nt);
    }

    int fT(vector<int>& nums,vector<vector<int>>& dp) {
         int n=nums.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
       
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= -1; j--) {
                int t = 0;
                if (j == -1 || nums[i] > nums[j])
                    t = 1 + next[i+1];
                // notTake
                int nt = next[j+1];

                curr[j + 1] = max(t, nt);
            }
            next=curr;
        }
        return next[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        return fT(nums,dp);
    }
};