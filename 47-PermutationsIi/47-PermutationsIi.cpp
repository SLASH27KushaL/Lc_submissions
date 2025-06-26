// Last updated: 6/26/2025, 7:59:38 PM
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tempList;
        vector<bool> used(nums.size(), false);
        set<vector<int>> uniquePermutations;  // Set to store unique permutations

        backtrack(uniquePermutations, tempList, nums, used);

        // Convert set back to vector
        return vector<vector<int>>(uniquePermutations.begin(), uniquePermutations.end());
    }

private:
    void backtrack(set<vector<int>>& uniquePermutations, vector<int>& tempList, vector<int>& nums, vector<bool>& used) {
        if (tempList.size() == nums.size()) {
            uniquePermutations.insert(tempList);  // Store in set to remove duplicates
            return;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            tempList.push_back(nums[i]);
            used[i] = true;

            backtrack(uniquePermutations, tempList, nums, used);

            tempList.pop_back();
            used[i] = false;
        }
    }
};
