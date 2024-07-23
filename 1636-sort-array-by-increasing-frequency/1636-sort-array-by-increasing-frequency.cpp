class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // map where key is frequency, and value is a multiset of numbers with that frequency, sorted in descending order
        map<int, multiset<int, greater<int>>> mpp;
        for (const auto& [num, freq] : mp) {
            mpp[freq].insert(num);
        }

        vector<int> ans;

        // iterate over the map in ascending order of frequency
        for (const auto& [freq, numSet] : mpp) {
            for (int num : numSet) {
                for (int i = 0; i < freq; ++i) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};
