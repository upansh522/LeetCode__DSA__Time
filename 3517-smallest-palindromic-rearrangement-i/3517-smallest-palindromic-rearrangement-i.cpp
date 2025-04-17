class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mp;
        int n=s.size();
        for (int i=0;i<n;i++){
            mp[s[i]]++;
        }
        char c;
        int i=0;
        for (auto it:mp){
            if (it.second%2!=0)c=it.first;
            while(it.second>1){
                s[i]=it.first;
                s[n-1-i]=it.first;
                it.second-=2;
                i++;
            }
        }
        if (c){
            s[i]=c;
        }
        return s;
    }
};