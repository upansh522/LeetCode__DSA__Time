class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans;

        if (nums.size()>=4)
        ans=min({nums[n-1] - nums[3],      
            nums[n-2] - nums[2],      
            nums[n-3] - nums[1],      
            nums[n-4] - nums[0]});  
        else 
        ans=0;

        return ans; 

    }
};