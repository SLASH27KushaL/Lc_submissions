// Last updated: 6/26/2025, 7:55:00 PM
class Solution {
    using ll = long long;
    static constexpr ll MOD = 1e9+7;
    
    // fast pow modulo in O(log e)
    ll modPow(ll base, ll exp) {
        ll res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) 
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    
public:
    int countGoodNumbers(long long n) {
        
        ll evenCount = (n + 1) / 2;
        
        ll oddCount  = n / 2;
        
        ll part1 = modPow(5, evenCount);
        ll part2 = modPow(4, oddCount);
        
        return int((part1 * part2) % MOD);
    }
};
