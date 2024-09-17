class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<triangle[i].size();j++){
                if (i==0 && j==0){
                    dp[0][0]=triangle[i][j];
                }else{
                    int sameInd=triangle[i][j];
                    if(j<triangle[i].size()-1){
                        sameInd+=dp[i-1][j];
                    }
                    else sameInd=INT_MAX;

                    int sameCol=triangle[i][j];
                    if (j>0)
                    sameCol+=dp[i-1][j-1];
                    else{
                        sameCol=INT_MAX;
                    }
                   dp[i][j]=min(sameCol,sameInd);
                }
            }
        }

        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};