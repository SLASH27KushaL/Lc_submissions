// Last updated: 6/26/2025, 7:55:30 PM
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (n < k) return false;
        if (n == k) return true;
        
        // Find frequency of each character
        int count[26] = {0};
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        
        int oddCount = 0;
        // Count characters with odd frequency
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                oddCount++;
            }
        }
        
        return (oddCount <= k);
    }
};
