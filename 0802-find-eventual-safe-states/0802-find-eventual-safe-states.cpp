class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>outDegree(graph.size(),0);
        unordered_map<int,multiset<int>>mp;
        for (int i=0;i<graph.size();i++)
        {
            for (auto it:graph[i])
            {
                mp[it].insert(i);
                outDegree[i]++;
            }
        }

        queue<int>q;
        vector<int>ans;
        for (int i=0;i<outDegree.size();i++)
        {
            if (outDegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int currNode=q.front();
            q.pop();
            for(auto it:mp[currNode])
            {
                outDegree[it]--;
                if (outDegree[it]==0)
                {
                    q.push(it);
                }
            }

            ans.push_back(currNode);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};