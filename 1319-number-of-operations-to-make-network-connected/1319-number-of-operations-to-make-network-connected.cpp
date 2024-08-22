class Solution {
public:
int find(vector<int> &parent, int x)
{
    if (parent[x]==x)
    return x;
    return find(parent, parent[x]);
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            // If there are fewer than n-1 edges, it's impossible to connect all computers
            return -1;
        }
        vector<int> parent(n),size(n,1);
        for (int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        int extra=0;

        for (int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            int up_u=find(parent,u);
            int up_v=find(parent,v);
            if (up_u==up_v)
            {
                extra ++;
                continue;
            }

            if (size[up_u]>size[up_v])
            {
                parent[up_v]=parent[up_u];
                size[up_u]+=size[up_v];
            }
            else {
                parent[up_u]=parent[up_v];
                size[up_v]=size[up_u];
            }

        }

        unordered_set<int> st;
        for (int i=0;i<n;i++)
        {
            int up=find(parent,i);
            st.insert(up);
        }

        if (st.size()>extra+1)
        return -1;
        
        return st.size()-1;        
    }
};