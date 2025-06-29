// Last updated: 6/29/2025, 11:44:16 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        const int INF = INT_MAX / 2;

        // 1) Build prefix-xor
        vector<int> px(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            px[i] = px[i-1] ^ nums[i-1];
        }

       
        vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
              
                for (int t = 0; t < i; ++t) {
                    if (dp[t][j-1] == INF) continue;
                    int segXor = px[i] ^ px[t];
                    int candidate = max(dp[t][j-1], segXor);
                    dp[i][j] = min(dp[i][j], candidate);
                }
            }
        }

        return dp[n][k];
    }
};
