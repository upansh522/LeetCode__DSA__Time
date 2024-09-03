class Solution {
public:

int take_first(vector<int> &nums, vector<int>&dp, int currHouse)
{
    if (currHouse==0)
    {
        return dp[0];
    }
    if (currHouse<0){
        return 0;
    }

    if (dp[currHouse]!=-1){
        return dp[currHouse];
    }
    else {
        return dp[currHouse]=max(nums[currHouse]+take_first(nums,dp,currHouse-2),take_first(nums,dp,currHouse-1));
    }
}

    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1)
        return nums[0];
        
        vector<int> dp(n,-1);
        vector<int> dpp(n,-1);
        dp[0]=0;
        int take_last=take_first(nums,dp,n-1);
        dpp[0]=nums[0];
        int incl_first=take_first(nums,dpp,n-2);

        return max(incl_first,take_last);
    }
};