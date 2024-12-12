class Solution {
public:
int f(vector<int>coins, int amt, vector<vector<int>>&dp, int ind){
    if (ind ==0){
        return (amt%coins[0])?INT_MAX:amt/coins[0];
    }

    if (dp[amt][ind]!=-1)
    return dp[amt][ind];

    int notTaken=f(coins,amt,dp,ind-1);
    int taken=INT_MAX;
    if (amt>=coins[ind])
    taken=f(coins,amt-coins[ind],dp,ind)+1;

    return dp[amt][ind]=min(notTaken,taken);
}
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(amt+1,vector<int>(n,-1));
        int ans=f(coins,amt,dp,n-1);
        if (ans==INT_MAX)
        return -1;
        else
        return ans;
    }
};