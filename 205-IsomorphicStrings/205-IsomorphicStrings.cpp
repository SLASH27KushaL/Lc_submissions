// Last updated: 6/26/2025, 7:58:00 PM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapST;
        map<char, char> mapTS;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char cs = s[i], ct = t[i];

            if (mapST.count(cs)) {
                if (mapST[cs] != ct) return false;
            } else {
                mapST[cs] = ct;
            }

            if (mapTS.count(ct)) {
                if (mapTS[ct] != cs) return false;
            } else {
                mapTS[ct] = cs;
            }
        }

        return true;
    }
};
