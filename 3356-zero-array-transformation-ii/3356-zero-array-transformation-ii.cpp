class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size(),m=q.size();
        vector<int>prefix(m);
        for (int i=0;i<m;i++){
            int l=q[i][0],r=q[i][1],val=q[i][2];
            if (i==0){
                prefix[i]=(r-l+1)*val;
            } else{
                prefix[i]=prefix[i-1]+(r-l+1)*val;
            }           
        }

        int l=0,h=m-1;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum==0){
            return 0;
        }
        while(l<=h){
            int mid=(l+h)/2;
            if (prefix[mid]>=sum){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return (l+1>=m)?-1:l+1;
    }
};