class Solution {
public:

    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        sort (nums.begin(),nums.end());
        int cnt=1;
        for (int i=0;i<n-1;i++){
            if (cnt>n/3){
                ans.push_back(nums[i]);
                while(i<n-1 && nums[i]==nums[i+1])i++;
            }
           if(i<n-1 && nums[i]==nums[i+1]) {
            cnt++;
           }
           else{
            cnt=1;
           }
        }
         if (cnt>n/3){
                 if (find(ans.begin(),ans.end(),nums.back())==ans.end())
                ans.push_back(nums.back());
            }
        return ans;
        
    }
};