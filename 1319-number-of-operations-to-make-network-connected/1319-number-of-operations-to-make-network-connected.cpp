class Solution {
public:
    int find(vector<int> &parent, int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent, parent[x]);  // Path compression
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            // If there are fewer than n-1 edges, it's impossible to connect all computers
            return -1;
        }

        vector<int> parent(n), size(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int extra = 0;

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            int up_u = find(parent, u);
            int up_v = find(parent, v);
            if (up_u == up_v) {
                extra++;
                continue;
            }

            if (size[up_u] > size[up_v]) {
                parent[up_v] = up_u;
                size[up_u] += size[up_v];  // Correctly updating size
            } else {
                parent[up_u] = up_v;
                size[up_v] += size[up_u];  // Correctly updating size
            }
        }

        unordered_set<int> components;
        for (int i = 0; i < n; i++) {
            components.insert(find(parent, i));
        }

        int components_count = components.size();
        
        // If extra connections are enough to connect all components
        if (extra >= components_count - 1) {
            return components_count - 1;
        } else {
            return -1;
        }
    }
};
