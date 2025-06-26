// Last updated: 6/26/2025, 7:52:46 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return sum%k;
    }
};