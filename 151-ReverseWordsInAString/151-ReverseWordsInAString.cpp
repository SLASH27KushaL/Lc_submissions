// Last updated: 6/26/2025, 7:58:20 PM
class Solution {
public:
    string reverseWords(string s) {
        vector<string> spa;
        int flag = 0;
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (flag == 0 && s[i] != ' ') {
                flag = 1;
                ans += s[i];
            } else if (flag == 1 && s[i] != ' ') {
                ans += s[i];
            } else if (flag == 1 && s[i] == ' ') {
                spa.push_back(ans);
                ans = "";
                flag = 0;
            } else {
                continue;
            }
        }

        
        if (ans != "") {
            spa.push_back(ans);
        }

        string final = "";
        reverse(spa.begin(), spa.end());

        for (int i = 0; i < spa.size(); i++) {
            final += spa[i];
            if (i != spa.size() - 1) final += " ";
        }

        return final;
    }
};
