class Solution {
public:
int longestCommonPrefixLength(const string& s1, const string& s2) {
    int i = 0;
    while (i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
        i++;
    }
    return i;
}


    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        if (n==1)return {0};
        vector<int>prefix(n,0),suffix(n,0);
        for (int i=0;i<n-1;i++){
            int pre=longestCommonPrefixLength(words[i],words[i+1]);
            int suff=longestCommonPrefixLength(words[n-i-1],words[n-i-2]);
            prefix[i+1]=max(prefix[i],pre);
            suffix[n-i-2]=max(suffix[n-i-1],suff);
        }

        vector<int>ans(n);
        for (int i=0;i<n;i++){
            if (i==0){
                ans[i]=suffix[i+1];
            }
            else if(i==n-1){
                ans[i]=prefix[i-1];
            }
            else{
                ans[i]=max({prefix[i-1],suffix[i+1],longestCommonPrefixLength(words[i-1],words[i+1])});
            }
        }
        return ans;
    }
};