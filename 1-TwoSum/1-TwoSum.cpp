// Last updated: 6/26/2025, 8:00:12 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int left=nums[0];
    vector<int>index;
   map<int,int>sum;
   for(int i=0;i<nums.size();i++){
     if(sum.find(target-nums[i])!=sum.end()){
        index.push_back(i);
        index.push_back(sum[target-nums[i]]);
        return index;
     }
     sum[nums[i]]=i;
   }
   return {-1,-1};
    }
};