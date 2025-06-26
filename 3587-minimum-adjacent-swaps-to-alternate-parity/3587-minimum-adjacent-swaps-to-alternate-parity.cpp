class Solution {
public:
    int f(vector<int> nums, int num) {
        int i = 0, j = 0;
        int n = nums.size();
        int cnt = 0;

        while (j < n && i < n) {
            if (nums[i] != num) {
                while (j < n && nums[j] != num) j++;
                if (j == n) {
                    return -1;  // Can't find needed num
                }
                swap(nums[i], nums[j]);
                cnt+=j-i;
            }
            num = (num + 1) % 2;
            i++;
            j = max(i, j);
        }

        return cnt;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % 2;
        }
        int odd = f(nums, 1);
        int even = f(nums, 0);

        if (even == -1 && odd == -1) return -1;
        if (even == -1) return odd;
        if (odd == -1) return even;
        return min(even, odd);
    }
};
