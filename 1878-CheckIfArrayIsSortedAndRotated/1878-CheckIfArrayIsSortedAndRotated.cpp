// Last updated: 6/26/2025, 7:55:14 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int counter=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]){
                counter++;
            }
            }
            if(counter>1){
                return false;
            }

            else if(counter==1 || counter ==0){
              return true;
            }
  return true;
    }
};