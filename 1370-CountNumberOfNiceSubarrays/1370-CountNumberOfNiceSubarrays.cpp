// Last updated: 6/26/2025, 7:55:39 PM
class Solution {
public:
    int numberOfSubarraysatmost(vector<int>& nums, int k) {
      int l=0;int r=0;
      int count=0;
      int checker=0;
      while(r<nums.size()){
        if(nums[r]&1){
            checker++;
        }
        while(checker>k){
            if(nums[l]&1){
                checker--;
                l++;
            }
            else{
                l++;
            }
        }
        count+=r-l+1;  
        r++;    
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
    return  numberOfSubarraysatmost(nums,k)-numberOfSubarraysatmost(nums,k-1);
    }
};