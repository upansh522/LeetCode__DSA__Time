class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0,i=0,j=0;
        unordered_map<char,int>mp;
        while(j<n){
            if (mp[s[j]]>0){
                ans=max((j-i), ans);
                mp[s[i]]--;
                i++;
                continue;
            }
            mp[s[j]]++;
            j++;
        }
        ans=max(ans, j-i);
        return ans;
    }
};