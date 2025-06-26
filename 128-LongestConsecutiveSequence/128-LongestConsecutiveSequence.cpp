// Last updated: 6/26/2025, 7:58:33 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int prev = nums[0];
        int len = 1;
        int max_len = 1;
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == prev) {
                continue;
            }
            
            if (nums[i] - prev == 1) {
                len++;
            } else {
                max_len = max(max_len, len);
                len = 1;
            }
            
            prev = nums[i];
        }
        
        max_len = max(max_len, len);
        return max_len;
    }
};
