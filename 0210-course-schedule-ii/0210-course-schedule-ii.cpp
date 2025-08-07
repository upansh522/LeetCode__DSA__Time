class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        int m=pre.size();
        vector<int>indegree(n,0);
        vector<int>ans;
        vector<vector<int>> graph(n); 
        for (int i=0;i<m;i++){
            int v=pre[i][0];
            int u=pre[i][1];
            indegree[v]++;
            graph[u].push_back(v);
        }

        queue<int>qu;
        for (int i=0;i<n;i++){
            if (indegree[i]==0)qu.push(i);
        }
        int count=0;

        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            ans.push_back(node);
            count++;
            for (auto it:graph[node]){
                cout<<it<<endl;
                indegree[it]--;
                if (indegree[it]==0){
                    qu.push(it);
                }
            }
        }

        
        return (count==n)?ans:vector<int>{};
    }
};