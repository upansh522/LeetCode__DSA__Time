class Solution {
public:
    int f(vector<int>& prices, int ind, int limit, int b, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size() || limit == 0)
            return 0;

        if (dp[ind][limit][b] != -1)
            return dp[ind][limit][b];    

        int profit = 0;
        if (b) {
            // We can buy or skip
            int buy = -prices[ind] + f(prices, ind + 1, limit, 0, dp);
            int skip = f(prices, ind + 1, limit, 1, dp);
            profit = max(buy, skip);
        } else {
            // We can sell (this completes one transaction) or skip
            int sell = prices[ind] + f(prices, ind + 1, limit - 1, 1, dp);
            int skip = f(prices, ind + 1, limit, 0, dp);
            profit = max(sell, skip);
        }

        return dp[ind][limit][b] = profit;
    }

    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return f(prices, 0, 2, 1, dp);
    }
};
