class Solution {
public:
long long f(vector<int>& coins, int amount, int ind, vector<vector<long long>>&dp){
    if (ind==0){
        return (amount%coins[ind]==0)?long(amount/coins[ind]):INT_MAX;
    }
    if (dp[ind][amount]!=-1){
        return dp[ind][amount];
    }
    long long nt=f(coins, amount, ind-1, dp);
    long long t=INT_MAX;
    if (amount>=coins[ind]){
        t=1+f(coins, amount-coins[ind], ind, dp);
    }
    return dp[ind][amount]=min(t,nt);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>>dp(n, vector<long long>(amount+1,-1));
        long long ans=f(coins,amount, n-1, dp);
        return (ans>=INT_MAX)?-1:ans;
    }
};