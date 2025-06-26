// Last updated: 6/26/2025, 7:59:23 PM
class Solution {
public:
    int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (m < 0 || n < 0) return 0;
        if (grid[m][n] == 1) return dp[m][n] = 0;
        if (m == 0 && n == 0) return grid[0][0] == 0 ? 1 : 0;
        if (dp[m][n] != -1) return dp[m][n];

        int left = f(m - 1, n, grid, dp);
        int up = f(m, n - 1, grid, dp);
        return dp[m][n] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};
