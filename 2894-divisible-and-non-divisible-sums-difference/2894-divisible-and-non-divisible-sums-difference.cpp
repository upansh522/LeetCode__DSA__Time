class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=(n*(n+1))/2,num2=0;
        for (int i=1;i<=n;i++){
            int num=m*i;
            if (num>n){
                break;
            }
            num1-=num;
            num2+=num;
        }
        return num1-num2;
    }
};