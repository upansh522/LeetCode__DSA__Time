class Solution {
public:
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if (i == s.size()) return t.size() - j;
        if (j == t.size()) return s.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = f(s, t, i+1, j+1, dp);
        }

        int insert = 1 + f(s, t, i, j+1, dp);   // Insert character in s
        int del = 1 + f(s, t, i+1, j, dp);      // Delete character from s
        int rep = 1 + f(s, t, i+1, j+1, dp);    // Replace character in s

        return dp[i][j] = min({insert, del, rep});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(word1, word2, 0, 0, dp);
    }
};
