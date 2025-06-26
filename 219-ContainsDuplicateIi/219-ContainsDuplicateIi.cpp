// Last updated: 6/26/2025, 7:57:48 PM
class Solution{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                if (abs(i - hash[nums[i]]) <= k) {
                    return true;
                }
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};
