// Last updated: 6/26/2025, 7:54:36 PM
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
    long long n=nums.size();
    long long count=0;
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[j]==nums[i] && (i*j)%k==0){
                count++;
            }
        }
     }
     return count; 
    }
};