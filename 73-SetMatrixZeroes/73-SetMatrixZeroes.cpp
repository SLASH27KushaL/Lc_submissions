// Last updated: 6/26/2025, 7:59:11 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // First pass: mark the zero positions
        vector<pair<int, int>> zeroPositions;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroPositions.push_back({i, j});
                }
            }
        }
        
       
        for (auto& pos : zeroPositions) {
            int row = pos.first;
            int col = pos.second;
            
            for (int k = 0; k < n; k++) {
                matrix[row][k] = 0;
            }
            
            for (int k = 0; k < m; k++) {
                matrix[k][col] = 0;
            }
        }
    }
};
