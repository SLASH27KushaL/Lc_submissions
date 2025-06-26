// Last updated: 6/26/2025, 7:54:14 PM
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;

        // XOR elements of nums1 if nums2.size() is odd
        if (nums2.size() % 2 != 0) {
            for (int num : nums1) {
                res ^= num;
            }
        }

        // XOR elements of nums2 if nums1.size() is odd
        if (nums1.size() % 2 != 0) {
            for (int num : nums2) {
                res ^= num;
            }
        }

        return res;
    }
};
