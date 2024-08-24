class Solution {
public:
int find(vector<int>& parent,int x)
{
    if (parent[x]==x)
    {
        return x;
    }
    return parent[x]=find(parent,parent[x]);
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp;
        vector<string> name(accounts.size());
        vector<int> parent(accounts.size());
        for (int i=0;i<accounts.size();i++)
        {
            name[i]=accounts[i][0];
            parent[i]=i;
            for (int j=1;j<accounts[i].size();j++)
            {
                if (mp.find(accounts[i][j])!=mp.end())
                {
                   int parent1 = find(parent, i);
                    int parent2 = find(parent, mp[accounts[i][j]]);
                    if (parent1 != parent2) {
                        parent[parent1] = parent2;  
                    }
                }
                else {
                    mp[accounts[i][j]]=i;
                }
            }
        } 

        unordered_map<int, set<string>> emailGroups;
        for (int i = 0; i < accounts.size(); i++) {
            int rootParent = find(parent, i);
            for (int j = 1; j < accounts[i].size(); j++) {
                emailGroups[rootParent].insert(accounts[i][j]);
            }
        }

        // Prepare the result in the required format
        vector<vector<string>> mergedAccounts;
        for (auto& group : emailGroups) {
            vector<string> emails(group.second.begin(), group.second.end());
            emails.insert(emails.begin(), name[group.first]);  // Add the name at the beginning
            mergedAccounts.push_back(emails);
        }

        return mergedAccounts;          

    }
};