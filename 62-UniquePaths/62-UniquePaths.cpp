// Last updated: 6/26/2025, 7:59:24 PM
class Solution {
public:
int f(int m,int n,vector<vector<int>>&dp){
    if(m==0 && n==0){
        return 1;
    }
    if(m<0 || n<0){
        return 0;
    }

if(dp[m][n]!=-1){
    return dp[m][n];
}
int up=f(m-1,n,dp);
int left=f(m,n-1,dp);
return dp[m][n]=left+up;

} 
public:
    int uniquePaths(int m, int n) {
     vector<vector<int>> dp(m,vector<int>(n,-1));
     return f(m-1,n-1,dp);  
    }
};