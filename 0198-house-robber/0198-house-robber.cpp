class Solution {
public:
int f(vector<int> &nums, vector<int> &dp, int currHouse){
   if (currHouse == 0) {
            return dp[currHouse] = nums[0];
        }
        if (currHouse == 1) {
            return dp[currHouse] = std::max(nums[0], nums[1]);
        }
        if (dp[currHouse] != -1) {
            return dp[currHouse];
        }
        dp[currHouse] = std::max(nums[currHouse] + f(nums, dp, currHouse - 2), f(nums, dp, currHouse - 1));
        return dp[currHouse];
}


    int rob(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0; 
        if (n == 1) return nums[0]; 

        std::vector<int> dp(n, -1); 
        return f(nums, dp, n - 1);
    }
};