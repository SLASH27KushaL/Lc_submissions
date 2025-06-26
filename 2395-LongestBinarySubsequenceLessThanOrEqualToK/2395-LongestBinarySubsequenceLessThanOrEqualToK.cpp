// Last updated: 6/26/2025, 7:54:29 PM

class Solution {
public:
    int longestSubsequence(const string &s, long long k) {
        int n = s.size();
        int length = 0;
        long long powerval = 1;
        
      
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                ++length;
            }
            else if (powerval <= k) {
                k -= powerval;
                ++length;
            }
            
            
            if (powerval <= k) {
                powerval <<= 1;
            }
        }
        
        return length;
    }
};