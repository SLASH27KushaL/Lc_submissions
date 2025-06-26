// Last updated: 6/26/2025, 7:57:35 PM
class Solution {
public:
    int f(int ind, int prev_ind, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) return 0;

        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int pick = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            pick = 1 + f(ind + 1, ind, nums, dp);
        }
        int not_pick = f(ind + 1, prev_ind, nums, dp);

        return dp[ind][prev_ind + 1] = max(pick, not_pick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[ind][prev_ind + 1] to handle prev_ind = -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};
