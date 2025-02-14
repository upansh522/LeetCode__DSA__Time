#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        
        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);
        }
        
        string ans;
        unordered_set<char> included;
        
        // Collect characters with max frequency in order of last occurrence
        for (int i = s.size() - 1; i >= 0; --i) {
            if (freq[s[i]] == maxFreq && included.find(s[i]) == included.end()) {
                ans.push_back(s[i]);
                included.insert(s[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
