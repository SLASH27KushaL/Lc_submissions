// Last updated: 6/26/2025, 7:56:40 PM
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(combi(n, cost, dp), combi(n-1, cost, dp));
    }

    int combi(int n, vector<int>& cost, vector<int>& dp) {
        if (n <= 0) {
            return 0;  // Base case: no cost to start at the ground level
        }
        if (n == 1) {
            return cost[0];  // Base case: cost to reach the first step
        }
        if (dp[n] != -1) {
            return dp[n];  // Return cached result
        }
        dp[n] = cost[n-1] + min(combi(n-1, cost, dp), combi(n-2, cost, dp));
        return dp[n];
    }
};
