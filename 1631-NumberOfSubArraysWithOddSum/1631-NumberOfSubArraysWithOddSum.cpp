// Last updated: 6/26/2025, 7:55:22 PM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long res = 0;
        long long even_count = 1;
        long long odd_count = 0;
        long long prefix = 0;
        const int MOD = 1e9 + 7;

        for(int i = 0; i < arr.size(); i++) {
            prefix += arr[i];
            if (prefix % 2 == 0) {
                res += odd_count;
                even_count++;
            } else {
                res += even_count;
                odd_count++;
            }
        }

        return res % MOD;
    }
};
