class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int m=pre.size();
        vector<int>indegree(n,0);
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

        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            for (auto it:graph[node]){
                cout<<it<<endl;
                indegree[it]--;
                if (indegree[it]==0){
                    qu.push(it);
                }
            }
        }

        for (int i=0;i<n;i++){
            if (indegree[i]!=0)return false;
        }
        return true;
    }
};