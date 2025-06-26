// Last updated: 6/26/2025, 7:59:34 PM
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; 
        if (n < 0) {
            x = 1 / x; 
            long long absN = -(long long)n; 
            return helper(x, absN);
        }
        return helper(x, n);
    }
    
private:
    double helper(double x, long long n) {
        double ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
        return ans;
    }
};
