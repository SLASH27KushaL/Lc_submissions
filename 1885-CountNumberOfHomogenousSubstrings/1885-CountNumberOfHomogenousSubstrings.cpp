// Last updated: 8/11/2025, 3:40:44 AM
class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        long long c = 0;
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            long long len = j - i;
            c = (c + (len * (len + 1) / 2) % MOD) % MOD;
            i = j;
        }

        return (int)c;
    }
};
