// Last updated: 8/11/2025, 3:41:12 AM


class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if (n < 3) return s;

        string ans;
        ans.reserve(n);
        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            int count = j - i;
            if (count >= 3) {
                ans.append(2, s[i]);
            } else {
                ans.append(count, s[i]);
            }
            i = j;
        }

        return ans;
    }
};
