class Solution {
public:
void dfs(vector<unordered_set<int>> &graph,vector<int> &visited,int currNode,vector<int>&ans)
{
    visited[currNode]=1;
    for (auto it:graph[currNode])
    {
        if (visited[it]==0)
        {
            dfs(graph,visited,it,ans);
            visited[it]=1;
        }
    }
    ans.push_back(currNode);
}
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> graph(n);
        vector<int> rootNode (n,1);
        for (int i=0;i<prerequisites.size();i++){
            int course=prerequisites[i][0];
            int preReqcourse=prerequisites[i][1];
            rootNode[preReqcourse]=0;
            if (graph[preReqcourse].find(course)==graph[preReqcourse].end()){
            graph[course].insert(preReqcourse);}
            else {
                return {};
            }
        }

        vector<int>ans;
        stack<int>qu;
        vector<int> visited(n,0);
        for (int i=0;i<n;i++)
        {
            if (rootNode[i]==1)
            qu.push(i);
        }
        while(!qu.empty())
        {
            int currNode=qu.top();
            qu.pop();
            dfs(graph,visited,currNode,ans);
        }
        if (ans.size()==n)
        return ans;
        else
        return {};

    }
};