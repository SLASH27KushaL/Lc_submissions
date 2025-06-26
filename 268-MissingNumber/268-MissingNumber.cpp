// Last updated: 6/26/2025, 7:57:39 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=nums.size();
        vector<int>vec(nums.size()+1,0);
        
        for(int j=0;j<nums.size();j++){
            vec[(nums[j])]=1;
            
        }
     
      for(int k=0;k<=nums.size();k++){
        if(vec[k]==0){
           return k; 
        }
      }
        return 0;
    }
};

