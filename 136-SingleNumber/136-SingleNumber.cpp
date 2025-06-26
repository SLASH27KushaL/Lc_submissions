// Last updated: 6/26/2025, 7:58:29 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int xore=0;
       for(int i=0;i<nums.size();i++){
        xore=(xore)^(nums[i]);
       }
       return xore;
    }
};
