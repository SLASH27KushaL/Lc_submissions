// Last updated: 6/26/2025, 7:52:52 PM
class Solution {
public:
    vector<vector<int>> grid;
    int val = 0; 

    void solve(int row, int col, int size) {
        if (size == 1) {
            grid[row][col] = val++;
            return;
        }

        int subgrid = size / 2;

        solve(row, col + subgrid, subgrid); 
             solve(row + subgrid, col + subgrid, subgrid);
        solve(row + subgrid, col, subgrid);     
        solve(row, col, subgrid);              
    }

    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        grid.resize(size, vector<int>(size, 0));
        solve(0, 0, size);
        return grid;
    }
};

