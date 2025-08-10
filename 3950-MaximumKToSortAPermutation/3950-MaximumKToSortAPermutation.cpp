// Last updated: 8/11/2025, 3:37:55 AM
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        //we will be able to swap only when we will have nums[i] & nums[j]==k
    
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=i){
            ans.push_back(nums[i]);
        }
    }
      if (ans.empty()) return 0;
    int val=ans[0];
    for(int i=1;i<ans.size();i++){
      val=val&(ans[i]);
    }
    return val;
    }
};