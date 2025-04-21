class Solution {
public:
long long f(vector<int>&nums, int ind, int sym, vector<vector<long long>>&dp){
    int n=nums.size();
    if (ind==n)return 0;

    if (dp[ind][sym+1]!=-1)return dp[ind][sym+1];

    long long take= sym*nums[ind]+f(nums,ind+1,sym*-1,dp);
    long long nt=f(nums,ind+1,sym,dp);
    return dp[ind][sym+1]=max(take, nt);
}
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(3,-1));
        return f(nums,0, 1, dp);
    }
};