// Last updated: 6/26/2025, 7:54:07 PM
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int start = INT_MAX;
        int end = INT_MIN;
        for(int num : nums) {
            start = min(start, num);
            end = max(end, num);
        }
        int ans = 0;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(isRobberyPossible(mid, nums, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    
private:
    bool isRobberyPossible(int capability, vector<int>& nums, int minHouses) {
        int housesRobbed = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= capability) {
                housesRobbed++;
                i++; // skip for adjacent condition
            }
            if(housesRobbed >= minHouses) return true;
        }
        return false;
    }
};
