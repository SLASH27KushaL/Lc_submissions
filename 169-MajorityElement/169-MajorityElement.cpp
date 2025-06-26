// Last updated: 6/26/2025, 7:58:10 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int counter1=0;
      int dig=nums[0];
      for(int i=0;i<nums.size();i++){
        
        if(nums[i]==dig){
            counter1++;
        }
        else{
            counter1--;
        }
        if(counter1==0){
            counter1++;
            dig=nums[i];
        }
      }
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==dig){
            cnt++;
        }
        if(cnt>nums.size()/2){
            return dig;
        } 
    }
return -1;
    } 


};
