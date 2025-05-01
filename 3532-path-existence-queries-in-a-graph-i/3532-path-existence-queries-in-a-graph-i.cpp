class Solution {
public:
int BinarySerach(vector<int>& nums, int l, int h, int ind, int diff){
    while(l<=h){
        int mid=(l+h)/2;
        if (abs(nums[ind]-nums[mid])>diff){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return h;
}

int find_parent(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find_parent(parent, parent[x]);
        }
        return parent[x];
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& query) {
        vector<int>v(n);
        for (int i=0;i<n;i++){
            v[i]=i;
        }

        int m=nums.size();
        for (int i=0;i<m;i++){
            int ind=BinarySerach(nums,i,m-1,i,maxDiff);
            v[i]=ind;
        }

        m=query.size();
        vector<bool>ans(m);
        for (int i=0;i<m;i++){
            int start=query[i][0];
            int end=query[i][1];
            int abs_parent_start=find_parent(v,start);
            int abs_parent_end=find_parent(v,end);
            if (abs_parent_start==abs_parent_end){
                ans[i]=true;
            }else
            ans[i]=false;
        }
        return ans;
    }
};