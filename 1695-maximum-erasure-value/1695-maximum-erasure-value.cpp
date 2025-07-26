class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n, -1), prefix(n + 1, 0);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                check[i] = mp[nums[i]];
            }
            if (i > 0) check[i] = max(check[i], check[i - 1]);
            mp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = nums[i] + prefix[i];
        }

        int ans = 0;
        for (int j = 0; j < n; j++) {
            int i = check[j];
            ans = max(ans, prefix[j + 1] - prefix[i + 1]);
        }

        return ans;
    }
};
