class Solution {
public:
bool check(string &s, int i, int j, vector<vector<int>>&dp){
    if (i>=j)return 1;

    if (dp[i][j]!=-1)return dp[i][j];

    if (s[i]==s[j])return dp[i][j]=check(s,i+1,j-1,dp);
    else return 0;
}
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int maxLen=0;
        string res="";
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (check(s,i,j,dp)){
                    if (j-i+1>maxLen){
                        maxLen=j-i+1;
                        res=s.substr(i, j - i + 1);
                    }
                }
            }
        }        
        return res;
    }
};