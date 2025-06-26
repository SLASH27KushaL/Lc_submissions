// Last updated: 6/26/2025, 7:59:03 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    
        int low=0;
        int high=nums.size()-1;
        while(high>=low){
            int mid=low+((high-low)/2);
            if(target==nums[mid]){
                return true;
            }
            if(nums[mid]==nums[low]&& nums[mid]==nums[high]){
                low+=1;
                high-=1;
                continue;
            }

           
            if(nums[low]<=nums[mid]){
                //left part is sorted
                if(target>=nums[low] && target<=nums[mid]){
                    
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target<=nums[high] && target>=nums[mid]){
                  low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
      
     return false; }
};