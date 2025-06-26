// Last updated: 6/26/2025, 8:00:01 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans = strs[0];
        int n = strs.size();

        for (int i = 1; i < n; i++) {
            int j = 0;
            while (j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j]) {
                j++;
            }
            ans = ans.substr(0, j);
            if (ans == "") return "";
        }

        return ans;
    }
};
