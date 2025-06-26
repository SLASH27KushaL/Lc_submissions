// Last updated: 6/26/2025, 7:55:56 PM
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>drow={1,0,-1,0};
        vector<int>dcol={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 ||i==n-1|| j==0 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;

                    }
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
          if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] && vis[nr][nc]==0){
            q.push({nr,nc});
            vis[nr][nc]=1;
          }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
   if(grid[i][j]==1 && vis[i][j]==0){
    count++;
   }
            }
        }
        return count;


    }
};