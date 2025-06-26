// Last updated: 6/26/2025, 7:52:48 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using pii = pair<int,int>;
    int minMoves(vector<string>& g) {
        int r = g.size(); if (!r) return -1;
        int c = g[0].size(), INF = 1e9;
        vector<string> v = g;
        vector<vector<pii>> p(26);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (g[i][j] >= 'A' && g[i][j] <= 'Z')
                    p[g[i][j]-'A'].emplace_back(i,j);
        deque<pii> q;
        vector<vector<int>> d(r, vector<int>(c, INF));
        vector<bool> u(26);
        d[0][0] = 0;
        q.emplace_front(0,0);
        int di[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop_front();
            int t = d[x][y];
            if (x==r-1 && y==c-1) break;
            char z = g[x][y];
            if (z>='A'&&z<='Z' && !u[z-'A']) {
                for (auto& pr : p[z-'A']) {
                    int nx=pr.first, ny=pr.second;
                    if (t < d[nx][ny]) { d[nx][ny]=t; q.emplace_front(nx,ny); }
                }
                u[z-'A']=1;
            }
            for (auto& o : di) {
                int nx=x+o[0], ny=y+o[1];
                if (nx>=0&&nx<r&&ny>=0&&ny<c&&g[nx][ny]!='#'&&t+1<d[nx][ny])
                    d[nx][ny]=t+1, q.emplace_back(nx,ny);
            }
        }
        int res = d[r-1][c-1];
        return res==INF ? -1 : res;
    }
};
