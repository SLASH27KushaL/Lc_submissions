// Last updated: 6/26/2025, 7:57:30 PM
class Solution {
public:
    int f(vector<int>& coins, int index, vector<int>& dp){
        if(index == 0) return dp[index] = 0; 
        if(index < 0) return INT_MAX;
        if(dp[index] != -1) return dp[index];
        
        int ways = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int sub = f(coins, index - coins[i], dp);
            if(sub != INT_MAX){
                ways = min(ways, 1 + sub);
            }
        }
        return dp[index] = ways;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = f(coins, amount, dp);
        return (result == INT_MAX) ? -1 : result;
    }
};
