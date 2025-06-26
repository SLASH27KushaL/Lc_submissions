// Last updated: 6/26/2025, 7:52:42 PM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> rowsum(n, 0);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                rowsum[i] += grid[i][j];

        vector<long long> prefixrow(n, 0), suffixrow(n, 0);
        prefixrow[0] = rowsum[0];
        for (int i = 1; i < n; ++i)
            prefixrow[i] = prefixrow[i - 1] + rowsum[i];

        suffixrow[n - 1] = rowsum[n - 1];
        for (int i = n - 2; i >= 0; --i)
            suffixrow[i] = suffixrow[i + 1] + rowsum[i];

        for (int i = 0; i < n - 1; ++i) {
            if (prefixrow[i] == suffixrow[i + 1])
                return true;
        }

        vector<long long> colsum(m, 0);
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                colsum[j] += grid[i][j];

        vector<long long> prefixcol(m, 0), suffixcol(m, 0);
        prefixcol[0] = colsum[0];
        for (int j = 1; j < m; ++j)
            prefixcol[j] = prefixcol[j - 1] + colsum[j];

        suffixcol[m - 1] = colsum[m - 1];
        for (int j = m - 2; j >= 0; --j)
            suffixcol[j] = suffixcol[j + 1] + colsum[j];

        for (int j = 0; j < m - 1; ++j) {
            if (prefixcol[j] == suffixcol[j + 1])
                return true;
        }

        return false;
    }
};
