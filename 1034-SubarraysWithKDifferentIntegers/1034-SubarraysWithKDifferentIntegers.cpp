// Last updated: 6/26/2025, 7:56:04 PM
class Solution {
public:
    int subarraysWithKDistinctatmost(vector<int>& nums, int k) {
        int l=0;int r=0;
        map<int,int>mapp;
        int counter=0;
        while(r<nums.size())
        {
         mapp[nums[r]]++;
         while(mapp.size()>k){
            mapp[nums[l]]--;
            if(mapp[nums[l]]==0){
                mapp.erase(nums[l]);
            }
            l++;
         }
        counter+=r-l+1;
      r++;
        }
        return counter;    
        }
        int subarraysWithKDistinct(vector<int>& nums, int k){
return subarraysWithKDistinctatmost(nums,k)-subarraysWithKDistinctatmost(nums,k-1);
        }
};