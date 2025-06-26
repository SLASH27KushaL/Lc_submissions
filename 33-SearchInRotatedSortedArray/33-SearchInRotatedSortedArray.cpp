// Last updated: 6/26/2025, 7:59:51 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int answer=-1;
        int low=0;
        int high=nums.size()-1;
        while(high>=low){
            int mid=low+((high-low)/2);
            if(target==nums[mid]){
                return mid;
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
    return answer;}
};