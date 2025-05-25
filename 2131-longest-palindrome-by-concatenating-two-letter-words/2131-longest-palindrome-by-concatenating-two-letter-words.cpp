class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        int ans=0;
        int max_len=0;
        unordered_map<string, int>mp;
        for (int i=0;i<n;i++){
            string temp=words[i];
            mp[temp]++;            
        }
        for (int i=0;i<n;i++){
            string temp=words[i];
            string rTemp=temp;
            reverse(rTemp.begin(),rTemp.end());
            if (mp[temp]>0){
                if (temp[0]==temp[1]){
                    if (mp[temp]%2==0){
                        ans+=mp[temp];
                        mp[temp]=0;
                    }
                    else{
                        ans+=mp[temp]-1;
                        max_len=1;
                        mp[temp]=0;
                    }
                    continue;
                }
                else{
                    if (mp.find(rTemp)!=mp.end()){
                        if (mp[rTemp]>0){
                            mp[temp]--;
                            mp[rTemp]--;
                            ans+=2;
                        }
                    }
                }
            }
        }
        return (ans+max_len)*2;
    }
};