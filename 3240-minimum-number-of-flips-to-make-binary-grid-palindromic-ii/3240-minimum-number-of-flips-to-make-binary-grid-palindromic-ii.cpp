class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for (int i=0;i<n/2;i++){
            for (int j=0;j<m/2;j++){
                int first =grid[i][j];
                int second =grid[i][m-j-1];
                int third= grid[n-i-1][j];
                int fourth= grid[n-i-1][m-j-1];
                int ones= (first==0)+(second==0)+(third==0)+(fourth==0);
                int zeros=(first==1)+(second==1)+(third==1)+(fourth==1);
                ans+=min(zeros,ones);
            }
        }

        int similar=0,unsimilar=0;

        if (n%2!=0){
            for (int j=0;j<m/2;j++){
                int first =grid[n/2][j];
                int second=grid[n/2][m-j-1];

                if (first == second ){
                    similar+=1;
                }else {
                    unsimilar+1;
                    ans+=1;
                }
            }
        }

        if (m%2!=0){
            for (int j=0;j<n/2;j++){
                int first =grid[j][m/2];
                int second=grid[n-j-1][m/2];

                if (first == second ){
                    similar+=1;
                }else {
                    unsimilar+1;
                    ans+=1;
                }
            }
        }
        if (n%2!=0 && m%2!=0){
            ans+=(grid[n/2][m/2]==1);
        }

        if (similar%2!=0){
            if (unsimilar==0)
            ans+=2;
        }

        return ans;

    }
};