// Last updated: 6/26/2025, 7:57:00 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int counter=1;
        int target=nums[0];
        for(int i=1;i<nums.size();i++){
        if(nums[i]==target){
            counter++;
        }
        else{
            if(counter==1){
                return target;
            }
            else{
                counter=1;
                target=nums[i];
            }
        }

        }
  return target;  }
};