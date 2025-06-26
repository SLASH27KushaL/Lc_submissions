// Last updated: 6/26/2025, 7:59:50 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>output(2,-1);
        int counter=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                counter++;
                if(counter==1){
                    output[0]=i;
                }
                else{
                    output[1]=i;
                }
            }
        }
      if (counter==1){
        output[1]=output[0];
      }  
    return output;}
};