class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0;
        int count=0;
        while(i<arr.size() && count<3)
        {
            if (arr[i]%2!=0)
            count++;
            else{            
            count=0;
            }
            i++;
        }

        if (count==3)
        return true;
        else
        return false;
    }
};