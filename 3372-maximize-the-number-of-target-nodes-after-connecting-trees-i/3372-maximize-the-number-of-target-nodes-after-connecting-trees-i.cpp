class Solution {
public:
int dfs(vector<int>&visit, unordered_map<int,vector<int>>&tree,int node,int k){
    int t=0;
    for (auto it:tree[node]){
        if (visit[it]==0 && k>0){
        visit[it]=1;
        t+=1+dfs(visit,tree,it,k-1);}
    }
    return t;
}
vector<int> f(vector<vector<int>>& edge, int k){
    int n=edge.size();
    unordered_map<int,vector<int>>tree;
    for (int i=0;i<n;i++){
        int u=edge[i][0],v=edge[i][1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int m=tree.size();
    vector<int>ans(m,0);
    for (int i=0;i<m;i++){
    vector<int>visit(m,0);
    visit[i]=1;
    ans[i]=1+dfs(visit,tree,i,k);
    }
    return ans;
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int>tree1=f(edges1,k);
        vector<int>tree2=f(edges2,k-1);
        int extraPath=*max_element(tree2.begin(),tree2.end());
        int n=tree1.size();
        if (k>0){
        for (int i=0;i<n;i++){
            cout<<tree1[i]<< " ";
            tree1[i]+=extraPath;
            cout<<tree1[i]<<endl;
        }}
        return tree1;
    }
};