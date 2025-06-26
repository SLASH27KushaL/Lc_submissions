// Last updated: 6/26/2025, 7:54:56 PM
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        map<int,int>maxi;
        int n=nums.size();
   for(int i=0;i<n-1;i++){
     maxi[i]=(*max_element(nums.begin()+i+1,nums.end()));
   }
   int ans=INT_MIN;
   for(int i=0;i<n;i++){
  ans=max(ans,maxi[i]-nums[i]);
   }
   if(ans<=0){
    return -1;
   }
   return ans;
    }
};