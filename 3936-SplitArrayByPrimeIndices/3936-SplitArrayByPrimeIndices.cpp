// Last updated: 7/20/2025, 7:13:54 PM
class Solution {
public:
    
    vector<bool> sieve;

    
    bool isPrime(int x) {
        return sieve[x];
    }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        // 1) Build sieve up to n-1
        sieve.assign(n, true);
        if (n > 0) sieve[0] = false;
        if (n > 1) sieve[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i)
                    sieve[j] = false;
            }
        }

        long long sumPrimeIdx = 0, sumNonPrimeIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime(i)) 
                sumPrimeIdx += nums[i];
            else 
                sumNonPrimeIdx += nums[i];
        }

        return llabs(sumPrimeIdx - sumNonPrimeIdx);
    }
};