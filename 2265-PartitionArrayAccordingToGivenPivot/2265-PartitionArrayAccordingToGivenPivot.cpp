// Last updated: 6/26/2025, 7:54:39 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        map<int, int> hash;
        int pivotCount = 0;  // Count occurrences of pivot

        // Store occurrences in the map
        for (int num : nums) {
            hash[num]++;
        }

        vector<int> ans;

        for (int num : nums) {
            if (num < pivot) {
                ans.push_back(num);
            } else if (num == pivot) {
                pivotCount++;
            }
        }

        // Add all occurrences of pivot
        for (int i = 0; i < pivotCount; i++) {
            ans.push_back(pivot);
        }

        // Second pass: Add elements greater than pivot
        for (int num : nums) {
            if (num > pivot) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
