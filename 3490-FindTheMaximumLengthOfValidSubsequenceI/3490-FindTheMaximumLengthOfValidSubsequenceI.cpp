// Last updated: 7/20/2025, 7:14:50 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int e = 0; // even count
        int o = 0; // odd count

        // Count even and odd numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                o++;
            } else {
                e++;
            }
        }

        // Count max alternating subsequence starting with odd
        int oe = 0;
        int flag = 0; // 0: expect odd, 1: expect even
        for (int i = 0; i < n; i++) {
            if (flag == 0 && (nums[i] & 1)) {
                oe++;
                flag = 1;
            } else if (flag == 1 && ((nums[i] & 1) == 0)) {
                oe++;
                flag = 0;
            }
        }

        // Count max alternating subsequence starting with even
        int eo = 0;
        flag = 0; // 0: expect even, 1: expect odd
        for (int i = 0; i < n; i++) {
            if (flag == 0 && ((nums[i] & 1) == 0)) {
                eo++;
                flag = 1;
            } else if (flag == 1 && (nums[i] & 1)) {
                eo++;
                flag = 0;
            }
        }

        return max({o, e, oe, eo});
    }
};
