class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                }
            }
        }
        vector<int>ans(n,INT_MAX);

        for (int i=0;i<n;i++){
            if (dp[0][i]){
                ans[i]=0;
            }else{
            for (int j=i;j>=0;j--){
                if (dp[j][i]){
                    ans[i]=min(ans[i],ans[j-1]+1);
                }
            }}
        }
        
        return ans[n-1];
    }
};