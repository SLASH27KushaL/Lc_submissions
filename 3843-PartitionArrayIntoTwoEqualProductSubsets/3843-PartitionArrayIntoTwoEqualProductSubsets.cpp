// Last updated: 7/9/2025, 1:31:35 AM
class Solution {
public:
   
    bool dfs(const vector<int>& nums, int ind, long long tar) {
        if (ind == nums.size()) 
            return tar == 1;
        if (dfs(nums, ind + 1, tar)) 
            return true;
        if (nums[ind] != 0 && tar % nums[ind] == 0) {
            if (dfs(nums, ind + 1, tar / nums[ind])) 
                return true;
        }
        return false;
    }

   
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 prod128 = 1;
        for (int x : nums) {
            if (x == 0) 
                return false;
            prod128 *= x;
        }

       
        __int128 want = (__int128)target * target;
        if (prod128 != want) 
            return false;

        
        return dfs(nums, 0, target);
    }
};
