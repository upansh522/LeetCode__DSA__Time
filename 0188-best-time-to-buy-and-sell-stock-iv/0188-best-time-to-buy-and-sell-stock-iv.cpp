class Solution {
public:
int f(vector<int>& v, int ind, int buy, int trans, vector<vector<vector<int>>>& dp) {
        // Base case: If index is out of bounds or no transactions are left
        if (ind ==v.size() || trans == 0) {
            return 0;
        }

        // Memoization check
        if (dp[ind][buy][trans] != -1) {
            return dp[ind][buy][trans];
        }

        if (buy==1) {
            return dp[ind][buy][trans] = max(-v[ind] + f(v, ind +1, 0, trans, dp), f(v, ind + 1, 1, trans, dp));
        } else {
            return dp[ind][buy][trans] = max(v[ind] + f(v, ind + 1, 1, trans - 1, dp), f(v, ind + 1, 0, trans, dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(prices,0,1,k,dp);
    }
};