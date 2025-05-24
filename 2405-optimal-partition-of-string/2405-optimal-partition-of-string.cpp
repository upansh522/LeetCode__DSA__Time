class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int n=s.size(),ans=1;
        for (int i=0;i<n;i++){
            if (st.count(s[i])==0){
                st.insert(s[i]);
            }else{
                st.clear();
                st.insert(s[i]);
                ans++;
            }
        }
        return ans;
    }
};