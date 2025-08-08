// Last updated: 8/9/2025, 3:03:58 AM

class Solution {
public:
    int isPrime(int n) {
        if (n < 2) return 0; 
        if (n == 2 || n == 3) return 1;
        if (n % 2 == 0 || n % 3 == 0) return 0;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return 0;
        }
        return 1;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        for (auto it : hash) {
            if (isPrime(it.second)) {
                return true;
            }
        }
        return false;
    }
};