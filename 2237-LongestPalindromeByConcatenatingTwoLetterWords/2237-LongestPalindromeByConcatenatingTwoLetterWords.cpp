// Last updated: 6/26/2025, 7:54:42 PM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> palCount;
        vector<string> nonPal;
        for (auto &w : words) {
            if (w[0] == w[1]) {
                palCount[w]++;
            } else {
                nonPal.push_back(w);
            }
        }
        
        unordered_map<string,int> waiting;
        int nonPalPairs = 0;
        for (auto &w : nonPal) {
            string rev = { w[1], w[0] };
            if (waiting[rev] > 0) {
                waiting[rev]--;
                nonPalPairs++;
            } else {
                waiting[w]++;
            }
        }
        
        int palPairs = 0;
        bool centerAvailable = false;
        for (auto &p : palCount) {
            int cnt = p.second;
            palPairs += cnt / 2;
            if (cnt % 2 == 1)
                centerAvailable = true;
        }
        
        int totalPairs = nonPalPairs + palPairs;
        int ans = 4 * totalPairs;
        if (centerAvailable) ans += 2;
        
        return ans;
    }
};
