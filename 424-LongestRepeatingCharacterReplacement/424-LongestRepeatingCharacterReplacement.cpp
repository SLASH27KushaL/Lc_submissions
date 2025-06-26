// Last updated: 6/26/2025, 7:57:13 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0;
        int maxCount = 0;
        int maxLen = 0;
        map<char, int> hashh;

        while (r < s.size()) {
            hashh[s[r]]++;
            maxCount = max(maxCount, hashh[s[r]]);
            
            while (r - l + 1 - maxCount > k) {
                hashh[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
