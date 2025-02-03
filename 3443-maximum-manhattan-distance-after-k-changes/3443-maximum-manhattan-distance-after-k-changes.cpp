class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int diff=0,currX=0,currY=0;
        int ans=0,use=0;
        for (int i=0;i<n;i++){
            if (s[i]=='N'){
                currX++;
            }else if (s[i]=='S'){
                currX--;
            }else if (s[i]=='E'){
                currY++;
            }
            else if (s[i]=='W'){
                currY--;
            }

            if ((abs(currX)+abs(currY))-i-1!=diff && k>0){
                k--;
                use++;
                diff=abs(currX)+abs(currY)-i-1;
            }
                ans=max(ans,abs(currX)+abs(currY)+2*use);
        }
        return ans;
    }
};