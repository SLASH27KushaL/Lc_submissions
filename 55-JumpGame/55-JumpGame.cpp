// Last updated: 6/26/2025, 7:59:30 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int n=nums.size();
         if(n==1){
            return true;
        }
        int cur=0;
        int maxi=nums[0];
        for(int i=1;i<n;i++){
         if(i>maxi){
            return false;
         }
         maxi=max(maxi,(i+nums[i]));
          if(maxi>=n-1){
            return true;
        }
        }
       
        return false;
    }
};