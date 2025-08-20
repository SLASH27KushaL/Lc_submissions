// Last updated: 8/20/2025, 8:16:03 PM
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
            arr.push_back(abs(nums[i]));
        }
        sort(arr.begin(),arr.end());
        long long ans=0;
        for(int i=0;i<n;i++){
      auto it=upper_bound(arr.begin(),arr.end(),2*arr[i]);
      ans+=it-arr.begin()-i-1;
        }
return ans;
    }
};