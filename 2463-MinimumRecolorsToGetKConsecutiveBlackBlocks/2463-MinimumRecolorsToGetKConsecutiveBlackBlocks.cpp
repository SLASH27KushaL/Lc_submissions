// Last updated: 6/26/2025, 7:54:26 PM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int n = blocks.size();
        for (int i = 0; i <= n - k; i++) { // Fix here: i <= n - k
            int ct = 0;
            for (int j = i; j < i + k; j++) {
                if (blocks[j] == 'W') {
                    ct++;
                }
            }
            ans = min(ans, ct);
        }
        return ans;
    }
};
