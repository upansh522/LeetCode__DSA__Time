class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>initial,two_num;
        for (int i=0;i<nums.size();i++){
            initial.insert(nums[i]);
            for (int j=i;j<nums.size();j++){
                two_num.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>ans;

        for (auto it: initial)
        {
            for (auto itt:two_num){
                ans.insert(it^itt);
            }
        }

        return ans.size();
    }
};