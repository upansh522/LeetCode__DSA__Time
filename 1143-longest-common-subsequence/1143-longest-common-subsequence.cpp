class Solution {
public:
int f(string txt1, string txt2, int ind, int fromInd, vector<vector<int>>&dp){
    char c=txt1[ind];
    if (ind==txt1.size()-1){
        return (txt2.find(c,fromInd)!=string::npos)?1:0;
    }
    if (dp[ind][fromInd]!=-1)
    return dp[ind][fromInd];

    int notTaken=f(txt1,txt2,ind+1,fromInd,dp);
    int taken=0;
    int n=txt2.find(c,fromInd);
    if (n!=string::npos){
        fromInd=n;
        taken=f(txt1, txt2, ind+1, n, dp)+1;
    }

    return dp[ind][fromInd]=max(taken,notTaken);
}
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(text1, text2, 0, 0, dp);
    }
};