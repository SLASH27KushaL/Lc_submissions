// Last updated: 6/26/2025, 7:57:04 PM
class Solution {
public:
    int f(int ind, int tar, vector<int>& nums, vector<vector<int>>& dp) {
        if (tar < 0) return 0;
        if (ind == 0) {
            if (tar == 0 && nums[0] == 0) return 2; 
            if (tar == 0 || nums[0] == tar) return 1;
            return 0;
        }
        if (dp[ind][tar] != -1) return dp[ind][tar];

        int notPick = f(ind - 1, tar, nums, dp);
        int pick = 0;
        if (nums[ind] <= tar) {
            pick = f(ind - 1, tar - nums[ind], nums, dp);
        }

        return dp[ind][tar] = pick + notPick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;

        if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;

        int tar = (sum + target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, -1));
        return f(nums.size() - 1, tar, nums, dp);
    }
};
