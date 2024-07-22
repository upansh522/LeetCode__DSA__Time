class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> ans;
        int n=names.size();
        for (int i=0;i<n;i++)
        {
            ans.push_back({heights[i],names[i]});
        }

        sort(ans.begin(), ans.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        vector<string> result;
        for (int i=0;i<n;i++)
        {
            result.push_back(ans[i].second);
        }

        return result;

    }
};