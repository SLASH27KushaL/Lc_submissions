// Last updated: 6/26/2025, 7:59:40 PM
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempList;
        vector<bool> used(nums.size(), false);
        backtrack(result, tempList, nums, used);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& tempList, vector<int>& nums, vector<bool>& used) {
        if (tempList.size() == nums.size()) {
            result.push_back(tempList);
            return;
        }
        
        for (size_t i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            tempList.push_back(nums[i]);
            used[i] = true;
            
            backtrack(result, tempList, nums, used);
            
            tempList.pop_back();
            used[i] = false;
        }
    }
};
