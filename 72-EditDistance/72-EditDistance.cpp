// Last updated: 6/26/2025, 7:59:13 PM
class Solution {
public:
    int f(string &s, string &t, int ind1, int ind2, vector<vector<int>>& dp) {
        if (ind1 < 0) return ind2 + 1;
        if (ind2 < 0) return ind1 + 1; 

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        if (s[ind1] == t[ind2]) {
            return dp[ind1][ind2] = f(s, t, ind1 - 1, ind2 - 1, dp); 
        } else {
            int ins = 1 + f(s, t, ind1, ind2 - 1, dp);     
            int del = 1 + f(s, t, ind1 - 1, ind2, dp);     
            int repl = 1 + f(s, t, ind1 - 1, ind2 - 1, dp); 

            return dp[ind1][ind2] = min({ins, del, repl}); 
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(word1, word2, n - 1, m - 1, dp);
    }
};
