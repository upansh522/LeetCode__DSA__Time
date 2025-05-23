class Solution {
public:
bool check(vector<int>& nums, vector<vector<int>>& query){
    int n=nums.size(),m=query.size();
    vector<int>diffArray(n+1,0);
    for (int i=0;i<m;i++){
        diffArray[query[i][0]]++;
        diffArray[query[i][1]+1]--;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=diffArray[i];
        if (sum<nums[i])return false;
    }
    return true;
}
    int maxRemoval(vector<int>& nums, vector<vector<int>>& query) {
        sort(query.begin(), query.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
             if (!check(nums,query))return -1; // O(N)
             int n=nums.size(),m=query.size();
             priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int>&, vector<int>&)>> pq(
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1]; // max-heap by end
            });
             vector<int>diffArray(n+2,0);
             int ans=0,currInd=0;
             for (int i=0;i<n;i++){ //O(N
                while( currInd<m && query[currInd][0]==i){
                    pq.push(query[currInd]);
                    currInd++;
                }
                while(!pq.empty() && diffArray[i]<nums[i]){
                    auto temp=pq.top();
                    pq.pop();
                    if (i>=temp[0] && i<=temp[1]){
                    diffArray[i]++;
                    diffArray[temp[1]+1]--;
                    ans++;}
                }
                diffArray[i+1]+=diffArray[i];
             }
             return m-ans;
    }
};