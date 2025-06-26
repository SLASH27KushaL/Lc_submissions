// Last updated: 6/26/2025, 7:59:33 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int max_sum=INT_MIN;
        for( int num:nums){
           sum+=num;
           max_sum=max(max_sum,sum);
           if(sum<0){
            sum=0;
           }
        }
        return max_sum;    
}
};