// Last updated: 6/26/2025, 7:53:08 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=1;i<n;i++){
             maxi=max(abs(nums[i]-nums[i-1]),maxi);
        }
        maxi=max(abs(nums[n-1]-nums[0]),maxi);
  return maxi;
    }
};