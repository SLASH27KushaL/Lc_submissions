// Last updated: 6/26/2025, 7:57:36 PM
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int ans;
        for(int i=0;i<nums.size();i++){
            if(hash[nums[i]]>1){
             ans=nums[i];
             break;
            }
        }
return ans;
    }
};