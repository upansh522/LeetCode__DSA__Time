class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int, pair<int, char>> robo;
        for (int i = 0; i < healths.size(); i++) {
            robo[positions[i]] = {healths[i], directions[i]};
        }
        sort(positions.begin(), positions.end());

        stack<pair<int, int>> right, left;
        vector<int> result;

        for (int pos : positions) {
            auto it = robo[pos];
            if (it.second == 'R')
                right.push({pos, it.first});
            else
                left.push({pos, it.first});

                    while (!right.empty() && !left.empty() && right.top().first<left.top().first) {
                    int right_pos = right.top().first;
                    int right_health = right.top().second;
                    int left_pos = left.top().first;
                    int left_health = left.top().second;
                    right.pop(); left.pop();                   
                    if (right_health > left_health) {
                        right.push({right_pos, right_health - 1});
                    } else if (right_health < left_health) {
                        left.push({left_pos, left_health - 1});
                    }
                }
            
        }

        while (!right.empty()) {
            result.push_back({right.top().second});
            right.pop();
        }

        while (!left.empty()) {
            result.push_back({left.top().second});
            left.pop();
        }

        return result;

    }
};
