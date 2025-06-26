// Last updated: 6/26/2025, 7:53:12 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
            sum += nums[i];
        }
        
        int count = 0;
        for (int i = 0; i < n-1; i++) {
            int left = prefix[i];
            int right = sum - left;
            // either:
            if ( ((right - left) & 1) == 0 ) {
                count++;
            }
           
        }
        return count;
    }
};
