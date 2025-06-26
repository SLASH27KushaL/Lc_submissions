// Last updated: 6/26/2025, 7:53:34 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        map<int,int>hash1;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int>arr;
        int st=nums[0];
        arr.push_back(st);
        for(int i=1;i<nums.size();i++){
         if(nums[i]==st){
            continue;
         }
         else{
            arr.push_back(nums[i]);
            st=nums[i];
         }
        }
        int mini=*min_element(arr.begin(),arr.end());
        if(k>mini){
            return -1;
        }
      int ind=arr.size()-1;
      if(k==arr[ind]){
        return ind;
      }
      else{
        return ind+1;
      }
       
    }
};