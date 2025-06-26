class Solution {
public:
bool makeEqual(vector<int> nums, int k, int equ){
    int n=nums.size();
    int cnt=0;
    for (int i=0;i<n-1;i++){
        if (nums[i]!=equ){
            cnt++;
            nums[i]*=-1;
            nums[i+1]*=-1;
        }
    }

    if (nums.back()!=equ)return false;
    return cnt<=k?true:false;
}
    bool canMakeEqual(vector<int>& nums, int k) {
        return (makeEqual(nums,k,1)||makeEqual(nums,k,-1));
    }
};