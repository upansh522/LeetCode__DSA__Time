class Solution {
public:
    int passThePillow(int n, int time) {
        if (n==1)
        return n;

        int rem,divs;
        rem=time%(n-1);
        divs=time/(n-1);

        if (rem==0)
            {
                if (divs%2==0)
                {
                    return 1;
                }
                else{
                return n;}
            }
        

        if (divs%2==0)
        {
            return rem+1;
        }
        else{
            return n-rem;
        }
    }
};