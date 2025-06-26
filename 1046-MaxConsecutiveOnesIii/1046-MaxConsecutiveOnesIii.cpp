// Last updated: 6/26/2025, 7:56:01 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;int r=0;
        int maxlen=0;
        int zeroes=0;
        int len=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zeroes++;
            }
            while(zeroes>k){
               if(nums[l]==0){
                zeroes--;
              
               }
               l++;
                        }
            if(zeroes<=k){
              len=r-l+1;
              maxlen=max(maxlen,len);
              
            }
            r++;
            
        }
        return maxlen;
    }
};