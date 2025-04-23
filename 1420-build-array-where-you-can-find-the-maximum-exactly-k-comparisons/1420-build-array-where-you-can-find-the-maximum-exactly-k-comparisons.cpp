class Solution {
public:
    int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int numOfArrays(int n, int m, int k) {
        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            int temp = k;
            int j = i;

            // FIX: Proper loop condition
            while (j < m && temp > 1) {
                j++;
                temp--;
            }

            // FIX: check temp == 1 not temp-1==0
            if (temp == 1) {
                int left = j - i + 1;
                int rem = n - left;

                if (rem >= 0) {  
                    ans = (ans + modPow(j, rem, MOD)) % MOD;
                }
            }
        }
        return ans;
    }
};
