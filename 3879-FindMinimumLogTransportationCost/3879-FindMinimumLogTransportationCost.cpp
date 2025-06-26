// Last updated: 6/26/2025, 7:52:27 PM
class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost1 = 0;
        if (n > k) {
            cost1 = static_cast<long long>(n - k) * k;
        }
        long long cost2 = 0;
        if (m > k) {
            cost2 = static_cast<long long>(m - k) * k;
        }
        return cost1 + cost2;
    }
};