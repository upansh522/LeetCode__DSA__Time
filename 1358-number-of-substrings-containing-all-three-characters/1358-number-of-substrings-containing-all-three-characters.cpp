class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> mpp;
        int n = s.size();
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            while (j < n && mpp.size() <3) {
                mpp[s[j]]++;
                j++;
            }
            while (j <= n && mpp.size() > 2) {
                ans += n - j + 1;
                mpp[s[i]]--;
                if (mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
            }
        }

        return ans;
    }
};