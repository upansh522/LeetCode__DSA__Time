class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int prev=0;
        for (int i=1;i<n;i++){
           prev=max(prev+prices[i]-prices[i-1],prev);
        }
        return prev;
    }
};