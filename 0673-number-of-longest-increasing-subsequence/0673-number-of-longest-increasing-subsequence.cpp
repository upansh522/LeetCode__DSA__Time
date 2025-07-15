class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);     // Length of LIS ending at index i
        vector<int> cnt(n, 1);    // Number of LIS ending at index i

        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen)
                total += cnt[i];
        }

        return total;
    }
};
