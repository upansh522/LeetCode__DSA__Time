class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int m = s.size(), n = t.size();

        // suff[i] represents the minimum remaining characters in `t` that can still be matched after position `i` in `s`
        vector<int> suff(m, 0);
        int j = n - 1;

        // Compute suffix matches for valid characters in `s` that align with `t`
        for (int i = m - 1; i >= 0; --i) {
            if (j >= 0 && s[i] == t[j]) {
                j--;
            }
            suff[i] = (n - 1) - j;
        }

        vector<int> ans;
        int i = 0;
        j = 0;

        // Find valid sequences
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                ans.push_back(i);
                j++;
            } else if (i + 1 < m && suff[i + 1] >= n - (j + 1)) {
                ans.push_back(i);
                j++;
                i++;
                while (i < m && j < n) {
                    if (s[i] == t[j]) {
                        ans.push_back(i);
                        j++;
                    }
                    i++;
                }
                break;  // Exit as the sequence is found
            }
            i++;
        }

        if(ans.size()==n)
        return ans;
        return {};
    }
};
