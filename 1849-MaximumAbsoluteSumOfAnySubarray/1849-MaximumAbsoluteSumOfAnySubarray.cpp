// Last updated: 6/26/2025, 7:55:17 PM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, sum = 0;
        int maxAbs = 0;

        for (int num : nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            minSum = min(minSum, sum);
            maxAbs = max(maxAbs, abs(maxSum - minSum));
        }

        return maxAbs;
    }
};
