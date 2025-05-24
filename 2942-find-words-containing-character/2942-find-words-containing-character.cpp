class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int n=words.size();
        for (int i=0;i<n;i++){
            if (find(words[i].begin(),words[i].end(),x)!=words[i].end())ans.push_back(i);
        }
        return ans;
    }
};