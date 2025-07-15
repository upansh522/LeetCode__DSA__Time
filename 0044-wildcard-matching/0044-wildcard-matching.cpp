class Solution {
public:
    bool f(string& s, string& p, int i, int j, vector<unordered_map<int,bool>>&dp) {
        if (i == s.size() && j == p.size())
            return true;
        if (j == p.size())
            return false;

        if (i == s.size()) {
            for (int k = j; k < p.size(); k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i].find(j)!=dp[i].end())return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j]=f(s, p, i + 1, j + 1,dp);
        else {
            if (p[j] == '*') {
                return dp[i][j]= f(s, p, i + 1, j,dp) || f(s, p, i, j + 1,dp);
            }
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) { 
        int n=s.size();
        vector<unordered_map<int,bool>>dp(n);
        return f(s, p, 0, 0,dp); }
};