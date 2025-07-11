// Last updated: 7/11/2025, 6:11:50 PM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=INT_MIN;
        map<int,int>hash;
        while(j<n){
            hash[nums[j]]++;

            while(hash[nums[j]]>k){
                hash[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return (ans==INT_MIN)?-1:ans;
    }
};