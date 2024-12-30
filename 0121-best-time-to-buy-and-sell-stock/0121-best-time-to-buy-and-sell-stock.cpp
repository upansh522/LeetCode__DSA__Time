class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0,currPurchase=prices[0];
        for (int i=1;i<n;i++){
            if (prices[i]<currPurchase){
                currPurchase=prices[i];
            }
            else{
                ans=max(ans,prices[i]-currPurchase);
            }
        }
        return ans;
    }
};