class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> visited(n,INT_MAX);
        queue<pair<int,pair<int,int>>> heap;
        vector<vector<pair<int,int>>>graph(n);
        for (auto it : flights)
        {
            graph[it[0]].push_back({it[1],it[2]});
        }

        int ans=INT_MAX;
        visited[src]=0;

        heap.push({0,{0,src}});
        while(!heap.empty())
        {
            int size=heap.size();            
            for (int i=0;i<size;i++)
            {
              auto [currStop,currPos]=heap.front();
              int currNode=currPos.second;
              int currDist=currPos.first;
              heap.pop();
              if (currNode==dst)
              {
                ans=min(ans,currDist);
                continue;
              }
              if (currStop<=k){
              for (auto it: graph[currNode])
              {
                if (currDist+it.second<=visited[it.first]){
                heap.push({currStop+1,{currDist+it.second,it.first}});
                visited[it.first]=currDist+it.second;
                }
              }
              }
            }
        }

        if (ans==INT_MAX)
        return -1;
        else
        return ans;
    }
};