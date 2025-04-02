class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;  // Store the maximum triplet value
        int n = nums.size();

        // Loop through each possible triplet
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Calculate the triplet value
                    long long tripletValue = (long long)(nums[i] - nums[j]) * nums[k];
                    // Update the answer, ensuring it is non-negative
                    ans = max({ans, tripletValue, 0LL});
                }
            }
        }

        return ans;
    }
};
