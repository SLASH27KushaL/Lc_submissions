// Last updated: 6/26/2025, 7:58:03 PM
class Solution {
public:
int f(int size,vector<int>&nums,vector<int>&dp){
    if(size<0){
        return 0;
    }
    if(size==1){
    dp[size]=max(nums[size],nums[size-1]);
    return dp[size];
    }
    if(size==0){
        dp[size]=nums[size];
        return dp[size];
    }
    //pick;
    if(dp[size]!=-1){
        return dp[size];
    }
    int pick=nums[size]+f(size-2,nums,dp);
    //no pick
    int nopick=f(size-1,nums,dp);
    dp[size]=max(pick,nopick);
    return dp[size];
}
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
    vector<int>dp(n+1,-1);
        return f(n-1,nums,dp);
    }
};