// Last updated: 6/26/2025, 7:53:30 PM
#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;

class Solution {
public:

    vector<vector<int>> dp;

    int f(int c, int steps) {
        int &res = dp[c][steps];
        if (res != -1) return res;

        if (steps == 0) {
          
            return res = 1;
        }

        if (c < 25) {
            res = f(c + 1, steps - 1);
        } else {
            long long a = f(0, steps - 1);
            long long b = f(1, steps - 1);
            res = (a + b) % MOD;
        }
        return res;
    }

    int lengthAfterTransformations(const string& s, int t) {
        dp.assign(26, vector<int>(t + 1, -1));

        long long total = 0;
        for (char ch : s) {
            total = (total + f(ch - 'a', t)) % MOD;
        }
        return int(total);
    }
};
