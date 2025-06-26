// Last updated: 6/26/2025, 7:59:43 PM
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if (nums[0] > 1 || nums[n-1] < 1) return 1;

        int ans = 1;  
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) continue;  
            
            if (nums[i] == ans) {
                
                ans++;
            } else if (nums[i] > ans) {
                
                return ans;
            }
            
        }
        
        return ans;
    }
};
