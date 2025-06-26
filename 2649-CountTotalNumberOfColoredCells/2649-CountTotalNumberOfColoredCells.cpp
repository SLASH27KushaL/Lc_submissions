// Last updated: 6/26/2025, 7:54:10 PM
class Solution {
public:
    long long coloredCells(int n) {
       return (long long)n * n + (long long)(n - 1) * (n - 1);
    }
};
