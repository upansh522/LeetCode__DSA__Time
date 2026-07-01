class Solution {
public:
int f(string s, string t, int i, int j, vector<vector<int>>&dp){
    if (i<0)return j+1;
    if (j<0)return i+1;

    if (dp[i][j]!=INT_MAX)return dp[i][j];
    if (s[i]==t[j])return f(s,t,i-1,j-1,dp);
    return dp[i][j]=1+min(f(s,t,i-1,j, dp), f(s,t,i,j-1,dp));
}
    int minDistance(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        return f(s, t, m-1, n-1, dp);
        
    }
};