class Solution {
public:
int f(int amount, vector<int>& coins, int ind,  vector<vector<int>>&dp){
    if (ind==0){
        return (amount%coins[ind]==0)?1:0;
    }
    if (dp[ind][amount]!=-1)return dp[ind][amount];
    int t=0;
    if (amount>=coins[ind])
    t=f(amount-coins[ind], coins, ind, dp);
    int nt=f(amount, coins, ind-1, dp);
    return dp[ind][amount]=nt+t;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(amount, coins, n-1, dp);
    }
};