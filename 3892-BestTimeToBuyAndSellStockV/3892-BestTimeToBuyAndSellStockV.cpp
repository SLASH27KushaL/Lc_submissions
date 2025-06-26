// Last updated: 6/26/2025, 7:52:30 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG_INF = numeric_limits<long long>::min() / 2;
        vector<vector<long long>> prev(k+1, vector<long long>(3, NEG_INF));
        prev[0][0] = 0;

        for (int price : prices) {
            vector<vector<long long>> curr(k+1, vector<long long>(3, NEG_INF));
            for (int t = 0; t <= k; ++t) {
                curr[t][0] = max(curr[t][0], prev[t][0]);
                curr[t][1] = max(curr[t][1], prev[t][1]);
                curr[t][2] = max(curr[t][2], prev[t][2]);
                curr[t][1] = max(curr[t][1], prev[t][0] - price);
                curr[t][2] = max(curr[t][2], prev[t][0] + price);
                if (t < k) {
                    curr[t+1][0] = max(curr[t+1][0], prev[t][1] + price);
                    curr[t+1][0] = max(curr[t+1][0], prev[t][2] - price);
                }
            }
            prev.swap(curr);
        }

        long long ans = 0;
        for (int t = 0; t <= k; ++t) {
            ans = max(ans, prev[t][0]);
        }
        return ans;
    }
};
