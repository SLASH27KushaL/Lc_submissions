// Last updated: 8/11/2025, 3:39:49 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int count = 0, ans = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == maxi) {
                count++;
                ans = max(ans, count);
            } else {
                count = 0;
            }
        }

        return ans;
    }
};
