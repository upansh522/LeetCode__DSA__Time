class Solution {
public:
int AtmostK(vector<int>&nums, int k){
    int n=nums.size();
    int i=0,j=0;
    int ans=0,sum=0;
    while(j<n){
        sum+=nums[j];
        while(i<=j && sum>k){
            sum-=nums[i];
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return AtmostK(nums, goal)-AtmostK(nums,goal-1);
    }
};