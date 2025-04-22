class Solution {
public:
bool check(string word1, string word2){
    if (word1.size()==word2.size())return false;
    int j=0,i=0;
    for (i=0;i<word2.size();i++){
        if (word1[j]==word2[i])j++;
    }
    return (i-j==1)?true:false;
}
int f(vector<pair<int,string>>& words, int ind1, int ind2, vector<vector<int>>&dp ){
    int n=words.size();
    if (ind1==n)return 0;

    if (dp[ind1][ind2+1]!=-1)return dp[ind1][ind2+1];

    int t=0;
    if (ind2==-1 || check(words[ind2].second,words[ind1].second)){
        t=1+f(words, ind1+1,ind1,dp);
    }
    int nt=f(words, ind1+1,ind2, dp);
    return dp[ind1][ind2+1]=max(t,nt);
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<pair<int,string>>pr;
        for (int i=0;i<n;i++){
            pr.push_back({words[i].size(),words[i]});
        }
        sort (pr.begin(),pr.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));        
        return f(pr, 0, -1, dp);
    }
};