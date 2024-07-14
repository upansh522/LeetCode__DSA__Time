class Solution {
public:
    std::string countOfAtoms(std::string s) {
        std::stack<std::map<std::string, int>> st;
        std::map<std::string, int> current;
        int n = s.size();
        for (int i = 0; i < n;) {
            if (s[i] == '(') {
                st.push(current);
                current.clear();
                i++;
            } else if (s[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(s[i])) i++;
                int multiplier = (start == i) ? 1 : stoi(s.substr(start, i - start));
                if (!st.empty()) {
                    auto temp = current;
                    current = st.top();
                    st.pop();
                    for (auto &p : temp) current[p.first] += p.second * multiplier;
                }
            } else {
                int start = i++;
                while (i < n && islower(s[i])) i++;
                std::string atom = s.substr(start, i - start);
                start = i;
                while (i < n && isdigit(s[i])) i++;
                int count = (start == i) ? 1 : stoi(s.substr(start, i - start));
                current[atom] += count;
            }
        }
        std::string result;
        for (auto &p : current) result += p.first + (p.second == 1 ? "" : std::to_string(p.second));
        return result;
    }
};