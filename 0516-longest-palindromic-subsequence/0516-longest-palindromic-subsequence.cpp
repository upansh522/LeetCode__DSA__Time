class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());

        vector<int> prev(n, 0), curr(n, 0); // 1D DP tables

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] == reversed_s[j]) {
                    curr[j] = (i > 0 && j > 0 ? prev[j - 1] : 0) + 1;
                } else {
                    curr[j] = max((j > 0 ? curr[j - 1] : 0), (i > 0 ? prev[j] : 0));
                }
            }
            prev = curr; // Move current row to previous for the next iteration
        }
        return curr[n - 1];
    }
};
