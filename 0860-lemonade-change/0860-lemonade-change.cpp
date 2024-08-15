class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cash=0;
        int i=0;
        map<int,int> mp;
        while(i<bills.size())
        {
            mp[bills[i]]++;
            int change=bills[i]-5;

            if (change==5)
            {
                if (mp[5]>0)
                mp[5]--;
                else
                return false;
            }
            else if (change==15)
            {
                if (mp[5]>0 && mp[10]>0)
                {
                    mp[5]--;mp[10]--;
                }
                else if (mp[5]>0 && mp[10]==0)
                {
                    if (mp[5]-3>=0)
                    mp[5]-=3;
                    else 
                    return false;
                }
                else 
                return false;
            }
            i++;
        }

        return true;
    }
};