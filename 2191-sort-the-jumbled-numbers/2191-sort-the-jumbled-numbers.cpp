class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, unordered_multiset<int>> mp;

        for (int i = nums.size()-1; i >=0; i--) {
            int newNumber = 0;
            int originalNumber = nums[i];
            stack<int> st;

            if (nums[i] == 0) {
                st.push(mapping[0]);
            } else {
                while (nums[i] > 0) {
                    int digit = nums[i] % 10;
                    nums[i] /= 10;
                    st.push(mapping[digit]);
                }
            }

            
            while (!st.empty()) {
                int digit = st.top();
                st.pop();
                if (st.size()>0)
                newNumber += digit * pow(10,st.size());
                else
                newNumber+=digit;
            }

            mp[newNumber].insert(originalNumber);
        }

        int ind = 0;
        for (auto it : mp) {
            for (auto number : it.second) {
                nums[ind] = number;
                ind++;
            }
        }

        return nums;
    }
};