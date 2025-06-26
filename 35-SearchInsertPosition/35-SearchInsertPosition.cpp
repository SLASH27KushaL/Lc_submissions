// Last updated: 6/26/2025, 7:59:48 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int answer=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target){
                answer=i+1;
            }
           
        }
    
    return answer;}
};