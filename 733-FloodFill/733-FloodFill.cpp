// Last updated: 6/26/2025, 7:56:43 PM
class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor,vector<int>&drow,vector<int>&dcol,int iniColor){
ans[row][col]=newColor;
int n=image.size();
int m=image[0].size();
for(int i=0;i<4;i++){
int nrow=row+drow[i];
int ncol=col+dcol[i];
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor){
    dfs(nrow,ncol,ans,image,newColor,drow,dcol,iniColor);

}
}

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>>ans=image;
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,-1,0,1};

        dfs(sr,sc,ans,image,color,drow,dcol,iniColor);
        return ans;
    }
};