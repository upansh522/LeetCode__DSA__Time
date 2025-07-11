class Solution {
public:
int f(vector<int>& nums, int target, int ind, vector<unordered_map<int, int>>&dp){
    if(ind==0){
        int a=target-nums[ind];
        int s=target+nums[ind];
        if (a==0 && s==0)return 2;
        else if (a==0||s==0)return 1;
        else return 0;
    } 

    if (dp[ind].find(target)!=dp[ind].end())return dp[ind][target];
    int add=f(nums, target-nums[ind], ind-1, dp);
    int sub=f(nums, target+nums[ind], ind-1, dp);
    return dp[ind][target]=add+sub;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int, int>>dp (n);
        return f(nums,target, n-1, dp);
    }
};