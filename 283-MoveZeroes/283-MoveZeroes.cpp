// Last updated: 6/26/2025, 7:57:37 PM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //we need to move zeroes to end
       int j=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i%nums.size()]!=0){
           nums[j]=nums[i];
           ++j;
        
        }
       } 
        for(int k=j;k<nums.size();k++){
             nums[k]=0;
        }}
};