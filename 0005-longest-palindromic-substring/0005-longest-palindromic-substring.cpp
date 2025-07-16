class Solution {
public:
     bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 0;
        int start=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (isPalindrome(s, j, i, dp) && (i - j + 1 > ans)) {
                    ans = i-j + 1;
                    start = j;
                }
            }
        }
        return  s.substr(start, ans);
    }
};