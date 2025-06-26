// Last updated: 6/26/2025, 7:54:32 PM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) keyIndices.push_back(i);
        }

        set<int> ans;
        for (int idx : keyIndices) {
            for (int j = max(0, idx - k); j <= min(n - 1, idx + k); j++) {
                ans.insert(j);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};
