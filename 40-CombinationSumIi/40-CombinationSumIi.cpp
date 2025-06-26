// Last updated: 6/26/2025, 7:59:44 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        backtrack(candidates, 0, target);
        return ans;
    }

    void backtrack(vector<int>& nums, int index, int target) {
        if (target == 0) {  
            ans.push_back(arr);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue; 

            if (nums[i] > target) break;  

            arr.push_back(nums[i]);
            backtrack(nums, i + 1, target - nums[i]); // Move to next index
            arr.pop_back(); // Backtrack
        }
    }
};
