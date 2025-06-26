// Last updated: 6/26/2025, 7:55:34 PM
class Solution {
public:
  int f(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp) {
        if (ind1 < 0 || ind2 < 0) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        if (s1[ind1] == s2[ind2]) {
            return dp[ind1][ind2] = 1 + f(s1, s2, ind1 - 1, ind2 - 1, dp);
        }
        return dp[ind1][ind2] = max(f(s1, s2, ind1 - 1, ind2, dp), f(s1, s2, ind1, ind2 - 1, dp));
    }
    int minInsertions(string s) {
        int n = s.size();  
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return n-f(s, s1, n - 1, n - 1, dp);
    }
};