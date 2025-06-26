// Last updated: 6/26/2025, 7:59:22 PM
class Solution {
public:
    int f(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (n == 0 && m == 0) {
            return dp[n][m] = grid[0][0];
        }
        if (n < 0 || m < 0) {
            return 1e9; // Use a large number to avoid invalid paths
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        int up = f(n - 1, m, grid, dp);
        int left = f(n, m - 1, grid, dp);

        return dp[n][m] = grid[n][m] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, grid, dp);
    }
};
