class Solution {
public:
    int f(vector<int>& coins, int amt, vector<int>& dp) {
        if (amt == 0) return 0;
        if (dp[amt] != -1) return dp[amt]; 
        
        int minCoins = INT_MAX;
        for (int coin : coins) {
            if (amt >= coin) {
                int res = f(coins, amt - coin, dp);
                if (res != INT_MAX) {
                    minCoins = min(minCoins, 1 + res);
                }
            }
        }
        
        dp[amt] = minCoins;
        return dp[amt];
    }
    
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt + 1, -1); 
        int result = f(coins, amt, dp);
        return (result == INT_MAX) ? -1 : result;
    }
};
