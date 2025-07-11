// Last updated: 7/11/2025, 6:11:41 PM
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return -1; 
       map<int,int>hash;
       for(int i=0;i<n;i++){
        hash[nums[i]]++;
       }

 int ans=INT_MIN;
 int s=0;
 for(int i=0;i<n;i++){
    s+=nums[i];
 }
 for(int i=0;i<n;i++){
    //check for each one being an outlier
hash[nums[i]]--;
   int req=(s-nums[i]);

 if((req&1)==0){
 int res=req/2;
 if(hash[res]){
    ans=max(ans,nums[i]);
 } 
 }
 
hash[nums[i]]++;
 }
        return (ans == INT_MIN ? -1 : ans);
    }
};