// Last updated: 8/6/2025, 7:44:07 PM
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int i = 1;
        int n = nums.size();
        int j = n - 1;
        long long ans = 0;
        while (j >= i) {
            ans += nums[i];
            i += 2;
            j--;
        }
        return ans;
    }
};