// Last updated: 6/26/2025, 7:54:30 PM
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
          if(arr.empty()){
            arr.push_back(nums[i]);
          }
          else if(nums[i]-arr[0]<=k){
            arr.push_back(nums[i]);
          }
          else{
            ans.push_back(arr);
            arr.clear();
            arr.push_back(nums[i]);
          }
        }
        if(!(arr.empty())){
         ans.push_back(arr);
        }
        return ans.size();
    }
};