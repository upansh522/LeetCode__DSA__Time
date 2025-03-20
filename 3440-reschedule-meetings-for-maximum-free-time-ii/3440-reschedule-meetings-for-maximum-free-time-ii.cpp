#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> inter;
        vector<pair<int, int>> interTime;
        
        // Initialize first interval
        interTime.push_back({0, startTime[0]});
        inter.push_back(startTime[0]);
        
        for (int i = 1; i < n; i++) {
            interTime.push_back({endTime[i - 1], startTime[i]});
            inter.push_back(startTime[i] - endTime[i - 1]);
        }
        
        // Last interval
        interTime.push_back({endTime[n - 1], eventTime});
        inter.push_back(eventTime - endTime[n - 1]);
        
        // Use ordered set (BST) for efficient look-up
        multiset<int> interSet(inter.begin(), inter.end());

        int ans = 0;
        
        for (int i = 0; i < interTime.size() - 1; i++) {
            int meet = interTime[i + 1].first - interTime[i].second;
            
            // Remove current interval from set to avoid self-comparison
            interSet.erase(interSet.find(inter[i]));
            interSet.erase(interSet.find(inter[i + 1]));
            
            // Binary search using lower_bound
            if (interSet.lower_bound(meet) != interSet.end()) {
                ans = max(ans, inter[i] + inter[i + 1] + meet);
            } else {
                ans = max(ans, inter[i] + inter[i + 1]);
            }
            
            // Reinsert removed elements
            interSet.insert(inter[i]);
            interSet.insert(inter[i + 1]);
        }
        
        return ans;
    }
};
