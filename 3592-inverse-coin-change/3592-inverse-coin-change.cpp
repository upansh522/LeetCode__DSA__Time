class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> ans;
        int n = numWays.size();

        for (int i = 0; i < n; i++) {
            int target = i + 1;
            // DP to count ways to form sum = target
            vector<int> dp(target + 1, 0);
            dp[0] = 1;

            for (int coin : ans) {
                for (int s = coin; s <= target; s++) {
                    dp[s] += dp[s - coin];
                }
            }

            int ways = dp[target];

            if (ways + 1 == numWays[i]) {
                ans.push_back(target);
            } else if (ways == numWays[i]) {
                continue;
            } else {
                return {};  // condition not satisfied
            }
        }

        return ans;
    }
};
