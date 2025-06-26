// Last updated: 6/26/2025, 7:57:52 PM
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
        if(n==1){
            return nums[0];
        }
    vector<int>dp1(n+1,-1);
    vector<int>dp2(n+1,-1);
        int one= f(n-2,nums,dp1);
        vector<int>dup;
        for(int i=1;i<n;i++){
            dup.push_back(nums[i]);
        }
        int two=f(n-2,dup,dp2);
        return max(one,two);
    }
};