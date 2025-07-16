class Solution {
public:
int f(string &s, int i, int j, vector<vector<int>>&dp){
    if (i>j)return 0;
    
    if (i==j)
    return (s[i]==s[j])?1:0;

    if (dp[i][j]!=-1)return dp[i][j];

    if (s[i]==s[j]){
        return dp[i][j]=2+f(s,i+1,j-1, dp);
    }
    return dp[i][j]=max(f(s, i, j-1,dp), f(s, i+1, j,dp));
}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return f(s, 0, n-1, dp);
    }
};