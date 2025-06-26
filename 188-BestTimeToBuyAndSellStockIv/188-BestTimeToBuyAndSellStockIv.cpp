// Last updated: 6/26/2025, 7:58:08 PM
class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, int lim, vector<vector<vector<int>>>& dp) {
        if (lim == 0 || ind == prices.size()) {
            return 0;
        }

        if (dp[ind][buy][lim] != -1) {
            return dp[ind][buy][lim];
        }

        if (buy == 0) {
            int take = -prices[ind] + f(prices, ind + 1, 1, lim, dp);
            int skip = f(prices, ind + 1, 0, lim, dp);
            return dp[ind][buy][lim] = max(take, skip);
        } else {
            int sell = prices[ind] + f(prices, ind + 1, 0, lim - 1, dp);
            int skip = f(prices, ind + 1, 1, lim, dp);
            return dp[ind][buy][lim] = max(sell, skip);
        }
    }

    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(prices, 0, 0, k, dp);
    }
};