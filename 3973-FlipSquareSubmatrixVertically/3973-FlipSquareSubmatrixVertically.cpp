// Last updated: 8/11/2025, 3:37:53 AM
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> arr = grid;

        int i = x;
        int j = x + k - 1;
        while (i < j) {
            for (int col = y; col <= y + k - 1; col++) {
                swap(arr[i][col], arr[j][col]);
            }
            i++;
            j--;
        }
        return arr;
    }
};
