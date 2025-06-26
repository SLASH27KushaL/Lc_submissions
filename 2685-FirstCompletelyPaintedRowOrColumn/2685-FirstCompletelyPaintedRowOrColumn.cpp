// Last updated: 6/26/2025, 7:54:08 PM
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();    // rows
        int m = mat[0].size(); // columns
        
        vector<int> rowCount(n, 0);
        vector<int> colCount(m, 0);
        
        // Map to store the position of each number in the matrix
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                map[mat[i][j]] = {i, j};
            }
        }
        
        int totalCells = n * m;
        for (int i = 0; i < totalCells; ++i) {
            auto cell = map[arr[i]];
            int row = cell.first;
            int col = cell.second;
            
            rowCount[row]++;
            colCount[col]++;
            
            if (rowCount[row] == m || colCount[col] == n) {
                return i;
            }
        }
        return -1;
    }
};