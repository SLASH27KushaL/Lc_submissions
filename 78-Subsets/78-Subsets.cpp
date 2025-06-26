// Last updated: 6/26/2025, 7:59:06 PM
class Solution {
public:
        vector<vector<int>>ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        subs(nums,0,arr);
        return ans;
    }
    void subs(vector<int>& nums,int index,vector<int>& arr ){
if(index==nums.size()){
     ans.push_back(arr);
return;
}
//pick
arr.push_back(nums[index]);
subs(nums,index+1,arr);
arr.pop_back();
subs(nums,index+1,arr);

    }
};