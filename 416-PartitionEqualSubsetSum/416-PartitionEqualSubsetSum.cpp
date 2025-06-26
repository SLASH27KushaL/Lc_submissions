// Last updated: 6/26/2025, 7:57:15 PM
class Solution {
public:
    int f(int index, int s, vector<vector<int>>& dp, vector<int>& nums) {
        if (s == 0) return dp[index][s] = 1;  
        if (index == 0) return dp[index][s] = (nums[0] == s ? 1 : 0); 
        if (dp[index][s] != -1) return dp[index][s];  

       
        if (f(index - 1, s, dp, nums) || (s >= nums[index] && f(index - 1, s - nums[index], dp, nums))) {
            return dp[index][s] = 1;
        }
        return dp[index][s]=0;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;  

        int s = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(s + 1, -1));

        return f(n - 1, s, dp, nums) == 1;
    }
};
