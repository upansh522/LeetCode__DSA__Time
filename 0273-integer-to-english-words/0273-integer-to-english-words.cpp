class Solution {
public:
    void makeHundredsString(int num, unordered_map<int, string>& mp,
                            string& temp) {
        int ones = num % 10;
        num = num / 10;
        int tens = num % 10;
        num = num / 10;
        int hundreds = num % 10;

        if (hundreds > 0) {
            temp += mp[hundreds] + " " + "Hundred";
        }

        if (tens > 1) {
            if (!temp.empty()) temp += " ";
            temp += mp[tens * 10];
            if (ones > 0) temp += " " + mp[ones];
        } else if (tens == 1 || ones > 0) {
            if (!temp.empty()) temp += " ";
            temp += mp[tens * 10 + ones];
        }
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        unordered_map<int, string> mp = {
            {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, 
            {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, 
            {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, 
            {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
            {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, 
            {80, "Eighty"}, {90, "Ninety"}
        };

        vector<int> hundreds;
        while (num > 0) {
            hundreds.push_back(num % 1000);
            num /= 1000;
        }

        string ans = "";
        vector<string> v = {"Thousand", "Million", "Billion"};

        for (int i = hundreds.size() - 1; i >= 0; --i) {
            string temp = "";
            makeHundredsString(hundreds[i], mp, temp);
            if (!temp.empty()) {
                if (!ans.empty()) ans += " ";
                ans += temp;
                if (i > 0) ans += " " + v[i - 1];
            }
        }

        return ans;
    }
};
