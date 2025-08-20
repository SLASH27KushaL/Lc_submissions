// Last updated: 8/20/2025, 8:16:04 PM
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        int qn = queries.size();
        int n = nums.size();
        if (n == 0) return 0;

        for (int i = 0; i < qn; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            if (k <= 0) continue;             
            if (l < 0) l = 0;                  
            if (r >= n) r = n - 1;             
            if (l > r) continue;

            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = static_cast<int>((1LL * nums[idx] * v) % MOD);
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
