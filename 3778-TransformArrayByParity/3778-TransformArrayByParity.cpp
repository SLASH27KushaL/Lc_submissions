// Last updated: 7/11/2025, 6:11:18 PM
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
          nums[i]=nums[i]%2;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};