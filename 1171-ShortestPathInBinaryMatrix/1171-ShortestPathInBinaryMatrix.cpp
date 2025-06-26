// Last updated: 6/26/2025, 7:55:49 PM
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
    return grid[0][0] == 0 ? 1 : -1;

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        dis[0][0] = 1;
        q.push({0, 0});

        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0 && dis[nr][nc] == INT_MAX) {
                    dis[nr][nc] = dis[r][c] + 1;
                    q.push({nr, nc});

                    if (nr == n - 1 && nc == n - 1)
                        return dis[nr][nc];
                }
            }
        }

        return -1;
    }
};
