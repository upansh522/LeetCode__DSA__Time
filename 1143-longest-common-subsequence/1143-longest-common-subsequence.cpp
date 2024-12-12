class Solution {
public:
    int f(string &txt1, string &txt2, int ind, int fromInd, vector<vector<int>> &dp) {
        if (ind == txt1.size()) {
            return 0; // Base case: Reached the end of txt1.
        }

        if (dp[ind][fromInd] != -1) {
            return dp[ind][fromInd]; // Return memoized result if available.
        }

        char c = txt1[ind]; // Current character from txt1.
        int notTaken = f(txt1, txt2, ind + 1, fromInd, dp); // Skip this character.
        int taken = 0;

        size_t pos = txt2.find(c, fromInd); // Find the character in txt2 starting from `fromInd`.
        if (pos != string::npos) {
            // If the character is found, continue the recursion.
            taken = 1 + f(txt1, txt2, ind + 1, pos + 1, dp);
        }

        // Store the result in the dp table and return the maximum.
        return dp[ind][fromInd] = max(taken, notTaken);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        // Use a 2D dp array to store results for all combinations of `ind` and `fromInd`.
        vector<vector<int>> dp(n1, vector<int>(n2 + 1, -1));

        return f(text1, text2, 0, 0, dp);
    }
};
