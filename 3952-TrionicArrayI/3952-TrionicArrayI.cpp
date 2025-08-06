// Last updated: 8/6/2025, 7:43:28 PM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false; 

        int flag = 0; 
        int phase_start = 0;

        for (int i = 1; i < n; i++) {
            if (flag == 0) {
                if (nums[i] > nums[i - 1]) {
                    continue;
                } else if (nums[i] < nums[i - 1]) {
                    if (i - 1 == 0) return false; 
                    flag = 1;
                    phase_start = i - 1;
                } else {
                    return false; 
                }
            } else if (flag == 1) {
                if (nums[i] < nums[i - 1]) {
                    continue;
                } else if (nums[i] > nums[i - 1]) {
                    if (i - 1 == phase_start) return false; 
                    flag = 2;
                    phase_start = i - 1;
                } else {
                    return false;
                }
            } else if (flag == 2) {
                if (nums[i] > nums[i - 1]) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        
        return flag == 2 && phase_start < n - 1;
    }
};
