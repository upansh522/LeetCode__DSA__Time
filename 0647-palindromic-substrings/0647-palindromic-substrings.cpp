class Solution {
public:
bool f(string &s, int i, int j,vector<unordered_map<int,bool>>&dp){
    if (j<i)return 1;

    if (dp[i].find(j)!=dp[i].end())return dp[i][j];

    if (s[i]==s[j]){
        return dp[i][j]=f(s,i+1,j-1,dp);
    }
    else{
        return dp[i][j]=0;
    }
}
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        vector<unordered_map<int,bool>>dp(n);
        for (int i=0;i<s.size();i++){
            for (int j=i;j<s.size();j++){
                if (f(s,i,j,dp))ans++;
            }
        }
        return ans;
    }
};