// Last updated: 6/26/2025, 7:56:53 PM
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int i = 0;
        int j = s1.size() - 1;

        while (j < s2.size()) {
            map<char, int> hash;

            // Build frequency map for the substring of s2
            for (int k = i; k <= j; k++) {
                hash[s2[k]]++;
            }

            // Check if this substring is a permutation of s1
            int flag = 1;
            map<char, int> s1Hash;
            for (char c : s1) {
                s1Hash[c]++;
            }

            for (auto& entry : s1Hash) {
                if (hash[entry.first] != entry.second) {
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                return true;
            }

            // Move the window
            i++;
            j++;
        }

        return false;
    }
};
