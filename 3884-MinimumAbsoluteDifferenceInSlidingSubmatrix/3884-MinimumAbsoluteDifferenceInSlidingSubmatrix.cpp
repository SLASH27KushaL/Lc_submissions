// Last updated: 7/9/2025, 1:31:25 AM
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
              
                std::set<int> uniq;
                for (int p = i; p < i + k; p++) {
                    for (int q = j; q < j + k; q++) {
                        uniq.insert(grid[p][q]);
                    }
                }

             
                if (uniq.size() < 2) {
                    res[i][j] = 0;
                    continue;
                }

               
                int mini = INT_MAX;
                auto prev = uniq.begin();
                for (auto it = std::next(uniq.begin()); it != uniq.end(); ++it) {
                    mini = std::min(mini, *it - *prev);
                    prev = it;
                }
                res[i][j] = mini;
            }
        }

        return res;
    }
};
