// Last updated: 7/11/2025, 6:12:03 PM
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++) {
            int rem = nums[i] % value;
            if (rem < 0) rem += value;
            hash[rem]++;
        }

        int val = 0;
        while (true) {
            int rem = val % value;
            if (hash[rem]) {
                hash[rem]--;
                val++;
            } else {
                return val;
            }
        }
        return -1;
    }
};
