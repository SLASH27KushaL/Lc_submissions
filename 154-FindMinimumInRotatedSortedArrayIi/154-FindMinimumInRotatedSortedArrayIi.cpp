// Last updated: 6/26/2025, 7:58:17 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int val=*min_element(nums.begin(),nums.end());
        return val;
    }
};