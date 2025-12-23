class Solution {
public:
    bool help(string &s, int i, int j, vector<vector<int>>& dp) {
        if (j <= i) return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = help(s, i + 1, j - 1, dp);

        return dp[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i; j--) {
                if (help(s, i, j, dp) && j - i + 1 > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};
