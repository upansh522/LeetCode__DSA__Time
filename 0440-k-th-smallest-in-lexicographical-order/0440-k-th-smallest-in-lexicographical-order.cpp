class Solution {
public:
int countSteps(int n, long long curr, long long prefix){
    int steps=0;
    while(curr<=n){
        steps+=min((long long )n+1,prefix)-curr;
        curr*=10;
        prefix*=10;
    }
    return steps;
}
    int findKthNumber(int n, int k) {
        long long curr=1;
        k--;
        while(k){
            int steps=countSteps(n, curr, curr+1);
            if (k-steps>=0){
                k-=steps;
                curr++;
            }else{
                k--;
                curr*=10;
            }
        }
        return curr;
    }
};