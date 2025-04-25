class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        unordered_set<int>st;
        for (auto it:nums){
            st.insert(it);
        }
        int k=st.size();
        int ans=0;
        for (int i=0;i<n;i++){
            unordered_set<int>stt;
            for (int j=i;j<n;j++){
                stt.insert(nums[j]);
                if (stt.size()==k)ans++;
                if (stt.size()>k){
                    break;
                }
            }
        }
        return ans;
        
    }
};