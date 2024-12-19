class Solution {
public:
    vector<int> z_algo(vector<int>& s) {
        int n = s.size();
        vector<int> z(n, 0); // Z-array to store the result
        int l = 0, r = 0;    // Left and right boundaries of the Z-box

        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            // Attempt to extend the Z-box starting from i
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }

    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> z = z_algo(nums);
        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            vector<int> nums2(nums.begin() + i, nums.end());
            vector<int> z2 = z_algo(nums2);            
            for (int j = i+1; j < n; j++) {
                if ((z[i] >= i && j>=i+i) || z2[j-i] >= (j-i)) { // Correct indexing for z2
                    ++ans;
                }
            }
        }
        return ans;
    }
};
