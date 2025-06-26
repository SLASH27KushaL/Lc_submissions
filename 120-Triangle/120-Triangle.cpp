// Last updated: 6/26/2025, 7:58:45 PM
class Solution {
public:
    int f(int n, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (m < 0 || m > n) return 1e9; 
        if (dp[n][m] != -1) return dp[n][m];
        if (n == 0 && m == 0) return dp[n][m] = triangle[0][0];

        int one = f(n - 1, m, triangle, dp);
        int two = f(n - 1, m - 1, triangle, dp);

        return dp[n][m] = triangle[n][m] + min(one, two);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = INT_MAX;
        for (int j = 0; j < triangle[n - 1].size(); ++j) {
            mini = min(mini, f(n - 1, j, triangle, dp));
        }
        return mini;
    }
};
