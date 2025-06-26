// Last updated: 6/26/2025, 7:55:01 PM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
           ans[i]=nums[nums[i]];
        }    
        return ans;
        }
};