class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n=maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        long long ans=0,sum=maximumHeight[0]+1;
        for (int i=0;i<n;i++){
            if (sum>maximumHeight[i]){
                sum=maximumHeight[i];
            }else{
                sum-=1;
            }
            ans+=sum;
            if (sum<=0)
            return -1;
        }
        return ans;
    }
};