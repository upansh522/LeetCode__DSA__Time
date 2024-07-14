class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<int>visited(n,0);        
        int flag=0;
        unordered_set<int> stA,stB;
        stA.insert(0);
        for (int i=0;i<n;i++)
        {
            queue<int>qu;
            if (visited[i]==0)
            {                
                qu.push(i),visited[i]=1;
            }

        while(!qu.empty())        
        {
            int size=qu.size();
            for (int i=0;i<size;i++)
            {
                int node=qu.front();
                qu.pop();
                for (auto it: graph[node])
                {
                    if (visited[it]==0){
                    qu.push(it);
                    if (flag==0)
                    {
                        if (stA.find(it)==stA.end())
                        {
                            stB.insert(it);
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        if (stB.find(it)==stB.end())
                        stA.insert(it);
                        else
                        return false;
                    }
                    }
                }
                visited[node]=1;
            }
            flag=(flag+1)%2;
        }
        }

        return true;
    }
};