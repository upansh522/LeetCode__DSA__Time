class Solution {
public:
    int k; // total number of unique elements

    // Recursive function to count complete subarrays starting at index i
    int countFrom(int i, int j, unordered_set<int> seen, const vector<int>& nums,vector<vector<int>>&dp) {
        if (j >= nums.size()) return 0;
        if (dp[i][j]!=-1)return dp[i][j];

        seen.insert(nums[j]);

        int count = 0;
        if (seen.size() == k) count = 1;

        // Recurse to the next j
        return dp[i][j]=count + countFrom(i, j + 1, seen, nums,dp);
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> totalSet(nums.begin(), nums.end());
        k = totalSet.size(); 
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            unordered_set<int> seen;
            total += countFrom(i, i, seen, nums,dp); 
        }

        return total;
    }
};