// Last updated: 6/26/2025, 7:53:45 PM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i+=3){
            if(abs(nums[i]-nums[i+1])>k || abs(nums[i]-nums[i+2])>k || abs(nums[i+1]-nums[i+2])>k){
                vector<vector<int>>lol;
                return lol;
            }
            else
            {
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
                
            }
        }
        
        
        return ans;
    }
};
