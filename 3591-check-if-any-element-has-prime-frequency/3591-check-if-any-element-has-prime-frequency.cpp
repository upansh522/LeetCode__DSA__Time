class Solution {
public:
bool isPrime(int n) {
    if (n <= 1) return false;        // 0, 1, and negatives are not prime
    if (n == 2) return true;         // 2 is the only even prime
    if (n % 2 == 0) return false;    // other even numbers are not prime

    for (int i = 3; i * i <= n; i += 2) {  // check odd divisors up to sqrt(n)
        if (n % i == 0) return false;
    }

    return true;
}

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for (auto it:mp){
            if (isPrime(it.second))return true;
        }
        return false;
    }
};