class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN, k=0;

        while(k<n){
            int i=k,j=k,sum=0;
            while(i<n){
            if(j>=n && j%n==i){
                break;
            }
            sum+=nums[j%n];
            ans=max(sum,ans);
            j++;
            if (sum<=0){
                i=j;
                sum=0;
            }
        }
        // if(j>=n && j%n==i){
        //         break;
        // }
        k=i+1;
        }
        return ans;
    }
};