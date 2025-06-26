// Last updated: 6/26/2025, 7:56:11 PM
class Solution {
public:
    int fun1(vector<int>& nums, int goal){
      int l=0;
      int r=0;
      int sum=0;
      int count=0;
      while(r<nums.size()){
        sum+=nums[r];
       while(l<=r && sum>goal){
        sum-=nums[l];
        l++;

       }
       count+=r-l+1;
       r++;
      }
      return count;
      };

       int numSubarraysWithSum(vector<int>& nums, int goal){
        return fun1(nums,goal)-fun1(nums,goal-1);
}};