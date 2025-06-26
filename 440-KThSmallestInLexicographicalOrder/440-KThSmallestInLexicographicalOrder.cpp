// Last updated: 6/26/2025, 7:57:10 PM
class Solution {
public:
    int findKthNumber(int n, int k) {
        long prefix = 1;
        k--; 

        while (k > 0) {
            long count = getCount(prefix, n);
            if (count <= k) {
                prefix++;
                k -= count;
            } else {
                prefix *= 10;
                k--;
            }
        }
        return prefix;
    }

private:
    long getCount(long prefix, int n) {
        long next = prefix + 1;
        long count = 0;

        while (prefix <= n) {
            count += min((long)n + 1, next) - prefix;
            prefix *= 10;
            next *= 10;
        }
        return count;
    }
};
