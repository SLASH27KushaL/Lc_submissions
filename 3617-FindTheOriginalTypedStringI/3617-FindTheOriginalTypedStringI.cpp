// Last updated: 7/9/2025, 1:31:59 AM
class Solution {
public:
    int possibleStringCount(string word) {
        map<int, int> hash;
        hash[0]++;
        int j = 0;
        char prev = word[0];

        for (int i = 1; i < word.size(); i++) {
            if (word[i] == prev) {
                hash[j]++;
            } else {
                j++;
                hash[j]++;
            }
            prev = word[i];
        }

        // Traverse the map correctly
        long long ans = 0;
        int count = 0;

        for (map<int, int>::iterator it = hash.begin(); it != hash.end(); ++it) {
            if (it->second > 1) {
                count++;
                ans += it->second;
            }
        }

        return ans - count + 1;
    }
};
