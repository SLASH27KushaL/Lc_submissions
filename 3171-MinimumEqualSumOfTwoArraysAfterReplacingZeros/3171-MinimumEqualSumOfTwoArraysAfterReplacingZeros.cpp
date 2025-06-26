// Last updated: 6/26/2025, 7:53:54 PM
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        long long count1 = 0, count2 = 0;

        for (int num : nums1) {
            s1 += num;
            if (num == 0) {
                count1++;
            }
        }

        for (int num : nums2) {
            s2 += num;
            if (num == 0) {
                count2++;
            }
        }

        long long min1 = s1 + count1;
        long long min2 = s2 + count2;

        if (min1 > min2) {
            if (count2 == 0) return -1; 
            return min1;
        }
        else if (min2 > min1) {
            if (count1 == 0) return -1;
            return min2;
        }
        else {
            return min1;
        }
    }
};