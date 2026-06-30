class Solution {
public:
int f(string s, string t, int i, int j, vector<vector<int>>&dp){
    if (i<0)return j+1;
    if (j<0)return i+1;
    if (dp[i][j]!=INT_MAX){
        return dp[i][j];
    }

    if (s[i]==t[j]){
        return dp[i][j]=f(s, t, i-1, j-1, dp);
    }
    int delOps=f(s, t, i-1, j, dp);
    int insOps=f(s,t,i,j-1, dp);
    int repOps=f(s, t, i-1, j-1, dp);
    return dp[i][j]=1+min({delOps, insOps, repOps});
}
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<vector<int>>dp(m, vector<int>(n,INT_MAX));
        return f(word1, word2, m-1, n-1, dp);        
    }
};