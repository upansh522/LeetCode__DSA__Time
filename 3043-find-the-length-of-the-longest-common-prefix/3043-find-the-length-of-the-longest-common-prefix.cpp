class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,bool>mp;
        int n=arr1.size(),m=arr2.size();
        for (int i=0;i<n;i++){
            string temp=to_string(arr1[i]);
            string str="";
            int j=0;
            while(str!=temp){
                str+=temp[j];
                j++;
                mp[str]=true;
            }
        }

        int ans=0;
        for (int i=0;i<m;i++){
            string temp=to_string(arr2[i]);
            string str="";
            int j=0;
            while(str!=temp){
                str+=temp[j];
                j++;
                if (mp[str]!=true){
                    break;
                }
                ans=max(ans,(int)str.size());
            }
        }

        return ans;
    }
};