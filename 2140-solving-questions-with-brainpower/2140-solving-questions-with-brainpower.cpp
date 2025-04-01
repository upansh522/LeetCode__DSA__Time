class Solution {
public:
long long f(vector<vector<int>>& ques, int ind, vector<long long>&dp){
    int n=ques.size();
    if (ind>=n){
        return 0;
    }
    if (dp[ind]!=-1){
        return dp[ind];
    }
    int incr=ques[ind][1];
    long long take=ques[ind][0]+f(ques,ind+incr+1,dp);
    long long notTake=f(ques,ind+1,dp);

    return dp[ind]=max(take,notTake);
}
    long long mostPoints(vector<vector<int>>& ques) {
        int n=ques.size();
        vector<long long>dp(n,-1);
        return f(ques,0,dp);
    }
};