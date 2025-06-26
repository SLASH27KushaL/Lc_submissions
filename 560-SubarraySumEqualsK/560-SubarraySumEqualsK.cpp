// Last updated: 6/26/2025, 7:56:54 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
    int counter=0;
   ;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            if(sum==k){
                counter++;
            }
        }
    }
    
       
    
     return counter;
    }
};