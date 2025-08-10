// Last updated: 8/11/2025, 3:40:32 AM
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // only start BFS on an unvisited land cell in grid2
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    // we'll assume it's a sub-island until we find evidence otherwise
                    bool isSub = true;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    vis[i][j] = true;

                    // check the starting cell
                    if (grid1[i][j] == 0) {
                        isSub = false;
                    }

                    // BFS over this grid2-island
                    while (!q.empty()) {
                        auto [r, c] = q.front(); 
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            // in-bounds, unvisited, and land in grid2
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m 
                                && !vis[nr][nc] 
                                && grid2[nr][nc] == 1) {
                                vis[nr][nc] = true;
                                
                                if (grid1[nr][nc] == 0) {
                                    isSub = false;
                                }
                                q.push({nr, nc});
                            }
                        }
                    }

                    if (isSub) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
