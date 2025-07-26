class Solution {
public:
int f(vector<int>& cuts, int i, int j, vector<vector<int>>&dp){
    if (i>j)return 0;

    if (dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for (int ind=i;ind<=j;ind++){
        int cost= cuts[j+1]-cuts[i-1]+ f(cuts, i, ind-1, dp) +f(cuts, ind+1, j, dp);
        ans=min(ans,cost);
    }
    return dp[i][j]=ans;
}
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        sort(cuts.begin(), cuts.end());
       cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>>dp(m+2,vector<int>(m+2,-1));
        return f(cuts, 1, m, dp);
    }
};