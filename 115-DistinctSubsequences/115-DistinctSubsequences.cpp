// Last updated: 6/26/2025, 7:58:48 PM
class Solution {
public:
    int f(string &s, string &t, int ind1, int ind2, vector<vector<int>>& dp) {
        if (ind2 < 0) return 1;
        if (ind1 < 0) return 0;

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if (s[ind1] == t[ind2]) {
            return dp[ind1][ind2] = f(s, t, ind1 - 1, ind2 - 1, dp) + f(s, t, ind1 - 1, ind2, dp);
        } else {
            return dp[ind1][ind2] = f(s, t, ind1 - 1, ind2, dp); // FIXED LINE
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(s, t, n - 1, m - 1, dp);
    }
};
