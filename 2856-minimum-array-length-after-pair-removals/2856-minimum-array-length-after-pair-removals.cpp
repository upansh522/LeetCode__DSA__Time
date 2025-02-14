class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
     unordered_map<int,int>mp;
     for (auto it:nums ) {
        mp[it]++;
     }  
     priority_queue<int>qu;
     for (auto it:mp){
        qu.push(it.second);
     }
     while(!qu.empty() && qu.size()>1){
        int first=qu.top();
        qu.pop();
        int second=qu.top();
        qu.pop();
        first--;
        second--;
        if (first>0)
        qu.push(first);
        if (second>0)
        qu.push(second);
     }

     return (!qu.empty())?qu.top():0;
    }
};