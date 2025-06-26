// Last updated: 6/26/2025, 7:56:32 PM
class Solution {
    const int mod = 1e9 + 7;

public:
    int f(int n, vector<int>& dp) {
        if (n < 0) return 0;
        if (n == 0) return 1; 
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = ((2* f(n - 1, dp)) % mod + f(n - 3, dp)) % mod;
    }

    int numTilings(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};
