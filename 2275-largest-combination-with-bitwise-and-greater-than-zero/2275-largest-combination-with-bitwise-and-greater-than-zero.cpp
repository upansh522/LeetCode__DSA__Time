class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;

        // Iterate over each bit position (from 0 to 31)
        for (int i = 0; i < 32; i++) {
            int count = 0;

            // Check the i-th bit of each number
            for (int num : candidates) {
                if (num & (1 << i)) {  // If the i-th bit is set
                    count++;
                }
            }

            // Update the maximum count of 1s for any bit position
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
