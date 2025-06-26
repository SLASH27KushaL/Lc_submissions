// Last updated: 6/26/2025, 7:56:09 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i-1][j];
                int leftDiag = (j > 0) ? matrix[i-1][j-1] : INT_MAX;
                int rightDiag = (j < m-1) ? matrix[i-1][j+1] : INT_MAX;

                matrix[i][j] += min({up, leftDiag, rightDiag});
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, matrix[n-1][j]);
        }

        return mini;
    }
};
