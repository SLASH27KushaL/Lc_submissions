// Last updated: 6/26/2025, 7:58:59 PM

class Solution {
public:
    set<vector<int>> uniqueSubsets;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        uniqueSubsets.clear(); 
        vector<int> arr;
        sort(nums.begin(),nums.end());
        poss(nums, 0, arr);

        return vector<vector<int>>(uniqueSubsets.begin(), uniqueSubsets.end());
    }

    void poss(vector<int>& nums, int index, vector<int>& arr) {
        if (index == nums.size()) { 
            uniqueSubsets.insert(arr); 
            return;
        }

        // Pick the current element
        arr.push_back(nums[index]);
        poss(nums, index + 1, arr);
        arr.pop_back();

        // Do not pick the current element
        poss(nums, index + 1, arr);
    }
};
