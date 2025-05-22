class Solution {
public:

    int binary_search(vector<int>&nums, int l, int h, int ind, int k){
        while(l<=h){
            int mid=(l+h)/2;
            if (abs(nums[mid]-nums[ind])<=k){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return h;
    }
    int findParent(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent, parent[node]); // Path compression
    }
    return parent[node];
}

    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& query) {
        vector<int>pare(n);
        for (int i=0;i<n;i++){
            pare[i]=i;
        }
        for (int i=0;i<n;i++){
            int right=binary_search(nums,i,n-1, i, maxDiff);
            pare[i]=right;
        }
        vector<bool>ans(query.size(),false);

        for (int i=0;i<query.size();i++){
            int start=query[i][0];
            int end=query[i][1];
            int abs_start=findParent(pare, start);
            int abs_end=findParent(pare,end);
            if (abs_start==abs_end){
                ans[i]=true;
            }
            
        }
        return ans;        
        
    }
};