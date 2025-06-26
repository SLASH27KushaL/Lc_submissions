// Last updated: 6/26/2025, 7:59:07 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0;
        map<char, int> mpp;
        int minlen = INT_MAX;
        int st_ind = -1;
        int count = 0;

        for (char c : t) {
            mpp[c]++;
        }

        int required = t.size();

        while (r < s.size()) {
            if (mpp[s[r]] > 0) {
                count++;
            }
            mpp[s[r]]--;

            while (count == required) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    st_ind = l;
                }

                mpp[s[l]]++;

                if (mpp[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        if (st_ind == -1) {
            return "";
        } else {
            return s.substr(st_ind, minlen);
        }
    }
};
