// Last updated: 6/26/2025, 7:55:16 PM
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // Direction vectors for up, right, down, left
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1)); // Result grid
        queue<pair<int, int>> q; // Queue to process cells

        // Initialize the queue with water cells and set their height to 0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // BFS to calculate the height of each cell
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int r = cell.first;
            int c = cell.second;
            int h = res[r][c];

            for (auto dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && res[nr][nc] == -1) {
                    res[nr][nc] = h + 1; // Visit the cell and set height
                    q.push({nr, nc});
                }
            }
        }

        return res;
    }
};
