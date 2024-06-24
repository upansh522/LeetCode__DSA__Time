class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]>0)
            mp[nums[i]]=i+1;
        }
        int i=1;
        while(!mp.empty())
        {
            if (mp.find(i)==mp.end())
            {
                return i;
            }
            mp.erase(i);
            i++;
        }

        return i;
    }
};