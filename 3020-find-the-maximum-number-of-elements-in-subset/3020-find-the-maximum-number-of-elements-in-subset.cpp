class Solution {
public:
    int square(int x) {
        const long long LIMIT = 1e9;
        long long sq = 1LL * x * x;

        if (sq > LIMIT)
            return -1;

        return (int)sq;
    }

    int helper(map<int, pair<int, bool>>& mp, int ele) {
        if (mp.find(ele) == mp.end()) {
            return -1;
        }
        if (mp[ele].first == 1) {
            mp[ele].second = true;
            return 1;
        }
        mp[ele].second = true;
        return 2 + helper(mp, square(ele));
    }

    int maximumLength(vector<int>& nums) {
        map<int, pair<int, bool>> mp;

        for (auto ele : nums) {
            mp[ele].first++;
            mp[ele].second = false;
        }
        int ans = 1;
        if (mp.find(1)!=mp.end()){
            if (mp[1].first%2==0){
                ans=mp[1].first-1;
            }
            else{
            ans=mp[1].first;}
        }
        mp.erase(1);

        for (auto& it : mp) {
            if (it.second.second == false) {
                ans = max(ans, helper(mp, it.first));
            }
        }

        return ans;
    }
};