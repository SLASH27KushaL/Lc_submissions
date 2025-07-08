// Last updated: 7/9/2025, 1:33:10 AM
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numWithIndex;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            numWithIndex.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(numWithIndex.begin(), numWithIndex.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        });

        vector<pair<int, int>> selected;
        for (int i = 0; i < k; i++) {
            selected.push_back(numWithIndex[i]);
        }

        
        sort(selected.begin(), selected.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });

        // Put values into ans
        vector<int> ans;
        for (auto& p : selected) {
            ans.push_back(p.first);
        }
        return ans;
    }
};
