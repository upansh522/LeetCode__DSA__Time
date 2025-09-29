class Solution {
public:
bool f(vector<int>&nums, int sum, int ind, vector<unordered_map<int, bool>>&dp){
    if (sum==0)return true;    
    if (ind<0)return false;

    if (dp[ind].find(sum)!=dp[ind].end())return dp[ind][sum];

    return dp[ind][sum]=f(nums, sum-nums[ind], ind-1, dp) || f(nums, sum, ind-1, dp);
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(), nums.end(),0);
        if (sum%2==1)return false;
        sum/=2;
        vector<unordered_map<int, bool>>dp(n);

        return f(nums, sum, n-1, dp);
        
    }
};