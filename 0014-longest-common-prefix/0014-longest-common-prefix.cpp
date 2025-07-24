class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans = "";
        string temp = "";
        int min_size = INT_MAX;
        for (auto s : str) {
            min_size = max(min_size, (int)s.size());
        }
        int i = 0;
        while (i < min_size) {
            temp.push_back(str[0][i]);
            int j = 0;
            while (j < str.size()) {
                if (str[j].substr(0, temp.size()) != temp) {
                    return ans;
                }
                j++;
            }
            ans = temp;
            i++;
        }
        return ans;
    }
};