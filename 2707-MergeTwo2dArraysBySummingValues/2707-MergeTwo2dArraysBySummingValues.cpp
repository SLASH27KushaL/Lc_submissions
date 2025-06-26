// Last updated: 6/26/2025, 7:54:04 PM
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int, int> hash;

        // Insert elements from nums1 into the map
        for (int i = 0; i < nums1.size(); i++) {
            hash[nums1[i][0]] = nums1[i][1];
        }

        for (int i = 0; i < nums2.size(); i++) {
            hash[nums2[i][0]] += nums2[i][1];
        }

        for (auto it : hash) {
            ans.push_back({it.first, it.second});
        }

        return ans;
    }
};
