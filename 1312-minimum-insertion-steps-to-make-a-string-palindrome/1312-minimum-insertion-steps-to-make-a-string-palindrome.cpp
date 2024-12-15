#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int f(const std::string& s, const std::string& t, int i, int j, std::vector<std::vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = 1 + f(s, t, i - 1, j - 1, dp);
        else
            return dp[i][j] = std::max(f(s, t, i, j - 1, dp), f(s, t, i - 1, j, dp));
    }

    int minInsertions(std::string s) {
        int n = s.size();
        std::string t = s;
        std::reverse(t.begin(), t.end());

        // Create a DP table initialized with -1
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));

        // Find the length of the longest palindromic subsequence
        int lpsLength = f(s, t, n - 1, n - 1, dp);

        // Minimum insertions required = total length - LPS length
        return n - lpsLength;
    }
};
