class Solution {
public:
int f(vector<int>&v,int ind, int buy, vector<vector<int>>&dp, int &fee){
    if (ind==v.size())return 0;
    if (dp[ind][buy]!=-1)return dp[ind][buy];

    if (buy) return dp[ind][buy]=max(-v[ind]+f(v,ind+1,0,dp,fee),f(v,ind+1,1,dp,fee));
    return dp[ind][buy]=max(v[ind]-fee+f(v,ind+1,1,dp,fee),f(v,ind+1,0,dp,fee));
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,0,1,dp,fee);
        
    }
};