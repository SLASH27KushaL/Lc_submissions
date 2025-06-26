// Last updated: 6/26/2025, 7:56:46 PM
class Solution {
public:
    int f(vector<int>& prices,int ind,int fee,int buy,vector<vector<int>>&dp){
          if (ind >= prices.size()) {
        return 0;
    }
    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0) {
        profit = max(0 + f(prices, ind + 1,fee, 0, dp), -prices[ind] + f(prices, ind + 1,fee, 1, dp));
    }

    if (buy == 1) { 
        profit = max(0 + f(prices,ind + 1,fee,1,dp), prices[ind]-fee + f(prices, ind + 1,fee, 0,dp));
    }
    return dp[ind][buy] = profit;
}

    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
        return f(prices,0,fee,0,dp);
    }
};