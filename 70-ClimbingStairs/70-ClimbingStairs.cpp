// Last updated: 6/26/2025, 7:59:16 PM
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);  // Initialize dp array with -1
        return combi(n, dp);
    }

    int combi(int n, vector<int>& dp) {
     if(n<=1){
        return 1;
     }         
     if(dp[n]!=-1){
        return dp[n];
     }
     dp[n]=combi(n-1,dp)+combi(n-2,dp);
     return dp[n];
    }
};
