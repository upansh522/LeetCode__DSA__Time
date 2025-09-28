class Solution {
public:
int f(vector<int>&nums, vector<int>&dp, int currHouse){
    if (currHouse<0)return 0;
    if (currHouse==0)return dp[0];

    if (dp[currHouse]!=-1)return dp[currHouse];

    return dp[currHouse]=max(nums[currHouse]+f(nums,dp,currHouse-2), f(nums, dp,currHouse-1));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1),dpp(n,-1);
        
        dp[0]=0;
        int take=f(nums,dp,n-1);
        dpp[0]=nums[0];
        int notTake=f(nums,dpp,n-2);

        return max(take,notTake);
    }
};