class Solution {
public:
int f(vector<int>& v, int ind, int buy, vector<vector<int>>&dp){
    if (ind>=v.size()){
        return 0;
    }

    if (dp[ind][buy]!=-1){
        return dp[ind][buy];
    }

    if (buy==1){
        return dp[ind][buy]=max(-v[ind]+f(v,ind+1,0,dp),f(v,ind+1,1,dp));
    }else
    return dp[ind][buy]=max(v[ind]+f(v,ind+2,1,dp),f(v,ind+1,0,dp));
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,0,1,dp)        ;
    }
};