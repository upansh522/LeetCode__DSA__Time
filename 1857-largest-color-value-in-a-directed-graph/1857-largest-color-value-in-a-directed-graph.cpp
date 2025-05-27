class Solution {
public:
int f(unordered_map<char,int>& mp){
    int ans=0;
    for (auto it:mp){
        ans=max(it.second,ans);
    }
    return ans;
}
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int m = edges.size();
        vector<vector<int>> graph(n);
        vector<int> inComing(n, 0);
        for (int i = 0; i < m; i++) {
            auto u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            inComing[v]++;
        }
        queue<int>qu;
        vector<unordered_map<char,int>>mp(n);

        for (int i=0;i<n;i++){
            if (inComing[i]==0){
                qu.push(i);
            }
        }
        int ans=-1;
        while(!qu.empty()){
            int currNode=qu.front();qu.pop();
            mp[currNode][colors[currNode]]++;
            ans=max(ans, f(mp[currNode]));
            for (auto node:graph[currNode]){
                inComing[node]--;
                for (int i=0;i<26;i++){
                    char c=i+'a';
                    mp[node][c]=max(mp[node][c],mp[currNode][c]);
                }
                if (inComing[node]==0)qu.push(node);
            }
        }
        return ans;
    }
};