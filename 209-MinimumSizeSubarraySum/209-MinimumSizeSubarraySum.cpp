// Last updated: 6/26/2025, 7:57:55 PM
class Solution {
public:
       int minSubArrayLen(int target, vector<int>& nums){
       int curr=0;
       int left=0;
       int len=INT_MAX;
       int right=0;
       while(left<nums.size()){
       curr+=nums[left];
       while(curr>=target){
     len=min(len,left-right+1);
     curr-=nums[right];
     right++;
    }
    left++;
       }

      if(len==INT_MAX){
        return 0;
      }
      return len;

    }
};