// Last updated: 7/9/2025, 1:33:01 AM
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
      int n=nums.size();
      map<int,int>hash;
      for(int i=0;i<n;i++){
        for(int j=0;j<nums[i].size();j++){
           hash[nums[i][j]]++;
        }
      }
      vector<int>ans;
      for(auto it:hash){
        if(it.second==n){
          ans.push_back(it.first);
        }
      }
      return ans;
    }
};