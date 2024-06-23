class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int i = 0, j;
        int ans = 0;

        for (j = 0; j < nums.size(); ++j) {
            while (!maxDeque.empty() && nums[j] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[j]);

            while (!minDeque.empty() && nums[j] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[j]);

            while (!maxDeque.empty() && !minDeque.empty() && (maxDeque.front() - minDeque.front() > limit)) {
                if (maxDeque.front() == nums[i]) maxDeque.pop_front();
                if (minDeque.front() == nums[i]) minDeque.pop_front();
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};