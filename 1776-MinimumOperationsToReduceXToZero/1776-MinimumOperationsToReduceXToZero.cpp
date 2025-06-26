// Last updated: 6/26/2025, 7:55:19 PM


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) total += num;

        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int maxLen = -1;
        int left = 0, currentSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            currentSum += nums[right];

            while (currentSum > target && left <= right) {
                currentSum -= nums[left++];
            }

            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : (nums.size() - maxLen);
    }
};
