class Solution {
public:
    int f(vector<int>& fir, vector<int>& sec, int ind1, int ind2,
          vector<vector<int>>& dp) {
        int n = fir.size();
        if (ind1 == n || ind2 == n)
            return 0;

            if (dp[ind1][ind2+1]!=-1)return dp[ind1][ind2+1];

        int t = 0;
        if (ind2==-1 || sec[ind2] < fir[ind1]) {
            t = 1 + f(fir, sec, ind1 + 1, ind1, dp);
        }
        int nt = f(fir, sec, ind1 + 1, ind2, dp);

        return dp[ind1][ind2+1]=max(t, nt);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        sort(pairs.begin(), pairs.end());
        vector<int> fir, sec;
        for (int i = 0; i < n; i++) {
            fir.push_back(pairs[i][0]);
            sec.push_back(pairs[i][1]);
        }
        return f(fir, sec, 0, -1,dp);
    }
};