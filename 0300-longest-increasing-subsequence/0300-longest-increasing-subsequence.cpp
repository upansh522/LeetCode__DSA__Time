class Solution {
public:
int f(vector<int>&nums, int ind, int ind2,vector<vector<int>>&dp){
    int n=nums.size();
    if (ind ==n)return 0;

    if (dp[ind][ind2+1]!=-1){
        return dp[ind][ind2+1];
    }

    int t=0;
    if (ind2==-1)
    t=1+f(nums,ind+1,ind,dp);
    else if (nums[ind]>nums[ind2]){
        t=1+f(nums,ind+1,ind,dp);
    }

    //notTake
    int nt=f(nums,ind+1,ind2,dp);

    return dp[ind][ind2+1]=max(t,nt);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
    }
};