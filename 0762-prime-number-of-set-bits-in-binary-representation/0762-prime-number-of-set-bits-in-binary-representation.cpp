class Solution {
public:

    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for (int i=left;i<=right;i++){
            int n=__builtin_popcount(i);

            int cnt=0;

        // Check for divisors from 1 to n
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }
        if (cnt <= 2 && cnt!=1)
        ans++;
    }

    return ans;
    }
};