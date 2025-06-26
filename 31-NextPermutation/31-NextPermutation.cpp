// Last updated: 6/26/2025, 7:59:52 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
        } 
        else {
           
            int min_ind = ind + 1;
            for (int i = ind + 1; i < n; i++) {
                if (nums[i] > nums[ind] && nums[i] < nums[min_ind]) {
                    min_ind = i;
                }
            }
            
            swap(nums[ind], nums[min_ind]);
            
            sort(nums.begin() + ind + 1, nums.end());
        }
    }
};

