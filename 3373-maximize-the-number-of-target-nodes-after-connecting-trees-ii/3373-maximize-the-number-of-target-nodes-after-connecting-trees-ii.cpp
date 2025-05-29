class Solution {
public:
    // Helper function to perform DFS and compute depths
    void dfs(int node, int parent, int depth, vector<int>& depths, const vector<vector<int>>& adj) {
        depths[node] = depth;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, depths, adj);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Step 1: Determine the number of nodes in each tree
        int n = edges1.size() + 1; // Number of nodes in Tree 1
        int m = edges2.size() + 1; // Number of nodes in Tree 2

        // Step 2: Build adjacency lists for both trees
        vector<vector<int>> adj1(n); // Adjacency list for Tree 1
        for (const auto& edge : edges1) {
            int u = edge[0], v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        vector<vector<int>> adj2(m); // Adjacency list for Tree 2
        for (const auto& edge : edges2) {
            int u = edge[0], v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        // Step 3: Compute depths for both trees using DFS
        vector<int> depths1(n, 0); // Depths for Tree 1
        dfs(0, -1, 0, depths1, adj1); // Root Tree 1 at node 0

        vector<int> depths2(m, 0); // Depths for Tree 2
        dfs(0, -1, 0, depths2, adj2); // Root Tree 2 at node 0

        // Step 4: Count nodes in Tree 2 at even and odd depths
        int evenDepthCount2 = 0, oddDepthCount2 = 0;
        for (int v = 0; v < m; v++) {
            if (depths2[v] % 2 == 0) {
                evenDepthCount2++;
            } else {
                oddDepthCount2++;
            }
        }
        int add=max(evenDepthCount2,oddDepthCount2);

        // Step 5: Compute the answer for each node in Tree 1
        vector<int> answer(n);
        int evenDepthCount1=0,oddDepthCount1=0;
        for (int u = 0; u < n; u++) {
            if (depths1[u] % 2 == 0) {
                evenDepthCount1++;
            } else {
                oddDepthCount1++;
            }
        }
        for (int i=0;i<n;i++){
            if (depths1[i]%2==0){
                answer[i]=add+evenDepthCount1;
            }else{
                 answer[i]=add+oddDepthCount1;
            }
        }

        return answer;
    }
};