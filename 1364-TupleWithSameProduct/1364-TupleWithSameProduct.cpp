// Last updated: 6/26/2025, 7:55:40 PM

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productMap;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int res = nums[i] * nums[j];
                productMap[res]++;
            }
        }
        
        int ans = 0;
        for (const auto& entry : productMap) {
            int count = entry.second;
            if (count >= 2) {
                int comb = (count * (count - 1)) / 2;
                ans += comb * 8;
            }
        }
        
        return ans;
    }
};
