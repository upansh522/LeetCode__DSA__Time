class Solution {
public:

bool isSubsetSum(vector<int>& nums, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true; // A sum of 0 is always possible

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}


    int minZeroArray(vector<int>& nums, vector<vector<int>>& query) {
        unordered_map<int,vector<int>>mp;
        int m=query.size(),n=nums.size();
        if (accumulate(nums.begin(),nums.end(),0)==0)return 0;

        int currInd=0;
        for (int i=0;i<m;i++){
            int l=query[i][0];
            int r=query[i][1];
            int val=query[i][2];
            for (int j=l;j<=r;j++){
                mp[j].push_back(val);
            }

            while(currInd<n && isSubsetSum(mp[currInd],nums[currInd])){
                currInd++;                
            }
            if (currInd==n){
                return i+1;
            }
        }
        return -1;
    }
};