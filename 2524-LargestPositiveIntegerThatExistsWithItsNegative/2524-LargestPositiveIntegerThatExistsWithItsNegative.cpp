// Last updated: 6/26/2025, 7:54:15 PM
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> ans;
        map<int, int> hash;
        
        // Store the count of each number
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                if (hash.find(-nums[i]) != hash.end()) { 
                    ans.push_back(nums[i]);
                }
            }
        }

        if (ans.empty()) {
            return -1;
        }

        return *max_element(ans.begin(), ans.end());
    }
};
