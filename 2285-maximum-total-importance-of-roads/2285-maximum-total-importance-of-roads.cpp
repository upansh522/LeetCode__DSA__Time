class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int deg[n];
        memset(deg,0,sizeof(deg));
        for(int i=0; i<roads.size(); i++){
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }
        sort(deg,deg+n);
        long long res = 0;
        for(int i=0; i<n; i++){
            res += static_cast<long long>(deg[i]) * (i+1); 
        }
        return res;
    }
};