class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> open,close;
        int n=s.size();

        for (int i=0;i<n;i++)
        {
            if (s[i]=='(')
            open.push_back(i);
            else if (s[i]==')')
            close.push_back(i);
        }

        while(!open.empty())
        {
            int open_brak=open.back();
            open.pop_back();
            int close_brak;

            for (int i=0;i<close.size();i++)
            {
                if (open_brak<close[i])
                {
                    close_brak=close[i];
                    close.erase(close.begin()+i);
                    break;
                }
            }

            reverse(s.begin()+open_brak,s.begin()+close_brak);
        }

        int i=0;
        while(i<s.size())
        {
            if (s[i]=='('|| s[i]==')')
            {
                s.erase(s.begin()+i);
            }
            else{
                i++;
            }
        }
        return s;
    }
};