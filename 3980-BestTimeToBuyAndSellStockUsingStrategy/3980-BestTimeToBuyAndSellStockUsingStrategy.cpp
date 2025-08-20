// Last updated: 8/20/2025, 8:16:06 PM
#include <vector>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        if (n == 0) return 0;

        // prefix of strategy * prices
        vector<long long> preStr(n);
        preStr[0] = 1LL * prices[0] * strategy[0];
        for (int i = 1; i < n; ++i)
            preStr[i] = preStr[i-1] + 1LL * prices[i] * strategy[i];

        // prefix of prices
        vector<long long> prePrice(n);
        prePrice[0] = prices[0];
        for (int i = 1; i < n; ++i)
            prePrice[i] = prePrice[i-1] + prices[i];

        long long cur = preStr[n-1];      
        long long best = cur;           

        for (int l = 0; l + k - 1 < n; ++l) {
            int r = l + k - 1;
            long long stratSum = preStr[r] - (l > 0 ? preStr[l-1] : 0LL);

          
            int mid = l + k/2;
            long long secondHalfSum = prePrice[r] - (mid > 0 ? prePrice[mid-1] : 0LL);

            long long newProfit = cur - stratSum + secondHalfSum;
            if (newProfit > best) best = newProfit;
        }

        return best;
    }
};
